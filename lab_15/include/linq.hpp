#ifndef LINQ_H_
#define LINQ_H_

#include <utility>
#include <vector>
#include <iterator>

namespace linq {
    namespace impl {
        template<typename T, typename Iter>
        class range_enumerator;
        template<typename T>
        class drop_enumerator;
        template<typename T>
        class take_enumerator;
        template<typename T, typename U, typename F>
        class select_enumerator;
        template<typename T, typename F>
        class until_enumerator;
        template<typename T, typename F>
        class where_enumerator;

        template<typename T>
        class enumerator {
        public:
            virtual T operator*() = 0; // Получает текущий элемент.
            virtual enumerator& operator++() = 0; // Переход к следующему элементу
            virtual operator bool() = 0; // Возвращает true, если есть текущий элемент

            auto drop(int count) {
                drop_enumerator<T> dropEnumerator(*this, count);
                return dropEnumerator;
            }

            auto take(int count) {
                take_enumerator<T> takeEnumerator(*this, count);
                return takeEnumerator;
            }

            template<typename U = T, typename F>
            auto select(F func) {
                select_enumerator<U, T, F> selectEnumerator(*this, std::move(func));
                return selectEnumerator;
            }

            template<typename F>
            auto until(F func) {
                until_enumerator<T, F> untilEnumerator(*this, std::move(func));
                return untilEnumerator;
            }

            auto until_eq(T value) {
                return until([value](const T& value_){ return value_ == value; });
            }

            template<typename F>
            auto where(F func) {
                where_enumerator<T, F> whereEnumerator(*this, std::move(func));
                return whereEnumerator;
            }

            auto where_neq(T value) {
                return where([value](const T& value_){ return value_ != value; });
            }

            std::vector<T> to_vector() {
                std::vector<T> out;
                copy_to(std::back_insert_iterator<std::vector<T>>(out));
                return out;
            }

            template<typename Iter>
            void copy_to(Iter it) {
                while (*this) {
                    it = **this;
                    ++(*this);
                    ++it;
                }
            }
        };

        template<typename T, typename Iter>
        class range_enumerator : public enumerator<T> {
        public:
            range_enumerator(Iter begin, Iter end) : begin_(begin), end_(end) {}


            T operator*() override {
                return *begin_;
            }

            range_enumerator& operator++() override {
                begin_++;
                return *this;
            }

            operator bool() override {
                return begin_ != end_;
            }

        private:
            Iter begin_, end_;
        };

        template<typename T>
        class drop_enumerator : public enumerator<T> {
        public:
            drop_enumerator(enumerator<T> &parent, int count) : parent_(parent), count_(count) {
            }

            T operator*() override {
                return *parent_;
            }

            drop_enumerator& operator++() override {
                ++parent_;
                return *this;
            }

            operator bool() override {
                for (; parent_ && count_ > 0; --count_)
                    ++(*this);
                return parent_;
            }

        private:
            enumerator<T> &parent_;
            int count_;
        };


        template<typename T>
        class take_enumerator : public enumerator<T> {
        public:
            take_enumerator(enumerator<T> &parent, int count) : parent_(parent), count_(count) {
            }

            T operator*() override {
                return *parent_;
            }

            take_enumerator& operator++() override {
                ++parent_;
                return *this;
            }

            operator bool() override {
                if (count_ == 0) {
                    return false;
                } else {
                    --count_;
                }
                return parent_;
            }

        private:
            enumerator<T> &parent_;
            int count_;
        };

        template<typename T, typename U, typename F>
        class select_enumerator : public enumerator<T> {
        public:
            select_enumerator(enumerator<U> &parent, F &&func) : parent_(parent), func_(std::move(func)) {
                if (parent_) {
                    lastEl = func_(*parent_);
                }
            }

            T operator*() override {
                return lastEl;
            }

            select_enumerator& operator++() override {
                ++parent_;
                if (parent_) {
                    lastEl = func_(*parent_);
                }
                return *this;
            }

            operator bool() override {
                return parent_;
            }

        private:
            T lastEl;
            enumerator<U> &parent_;
            F func_;
        };

        template<typename T, typename F>
        class until_enumerator : public enumerator<T> {
        public:
            until_enumerator(enumerator<T> &parent, F &&predicate) : parent_(parent), predicate_(std::move(predicate)) {
            }

            T operator*() override {
                return *parent_;
            }

            until_enumerator& operator++() override {
                ++parent_;
                return *this;
            }

            operator bool() override {
                return parent_ && !predicate_(*parent_);
            }

        private:
            enumerator<T> &parent_;
            F predicate_;
        };

        template<typename T, typename F>
        class where_enumerator : public enumerator<T> {
        public:
            where_enumerator(enumerator<T> &parent, F &&predicate) : parent_(parent), predicate_(std::move(predicate)) {
            }

            T operator*() override {
                return *parent_;
            }

            where_enumerator& operator++() override {
                if (!isFirst) {
                    ++parent_;
                }

                while (parent_ && !predicate_(**this)) {
                    ++parent_;
                }
                isFirst = false;
                return *this;
            }

            operator bool() override {
                if (isFirst)
                    ++(*this);
                return parent_;
            }

        private:
            enumerator<T> &parent_;
            F predicate_;
            bool isFirst = true;
        };


    } // namespace impl

    template<typename T>
    auto from(T begin, T end) {
        return impl::range_enumerator<typename std::iterator_traits<T>::value_type, T>(begin, end);
    }

} // namespace linq

#endif
