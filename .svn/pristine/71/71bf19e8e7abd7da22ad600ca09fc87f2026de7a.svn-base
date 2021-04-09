#include <cstddef>  // std::size_t
#include <string>  // std::string
#include <iostream>
#include <vector>
#include <string_view>
#include <charconv>

#if __cplusplus < 201703L
#error At least C++17 is required
#endif

namespace format {
    template<typename T, typename = void>
    struct is_print {
        static const bool value = false;
    };

    template<typename T>
    struct is_print<T, typename std::enable_if<std::is_integral_v<T>>::type> {
        static const bool value = true;
    };

    template<>
    struct is_print<bool> {
        static const bool value = true;
    };

    template<typename T>
    struct is_print<T, typename std::enable_if_t<std::is_same_v<std::string, decltype(std::declval<T>().format())> > > {
        static const bool value = true;
    };

    template<typename, typename = void> struct FormatHelper {
        std::size_t estimate_size() const = delete;
        void append_to(std::string &) const = delete;
    };

    template<>
    struct FormatHelper<bool> {
        explicit FormatHelper(const bool& value) : value(value) {}

        static constexpr std::size_t estimate_size() {
            return 8;
        }

        void append_to(std::string& s) const {
            if (value)
                s += "true";
            else
                s += "false";
        }

    private:
        bool value;
    };

    template<typename T>
    struct FormatHelper<T, typename std::enable_if<std::is_integral_v<T>>::type> {
        explicit FormatHelper(const T& value) : value(value) {}

        static constexpr std::size_t estimate_size() {
            return std::numeric_limits<T>::digits10 + 2;
        }

        void append_to(std::string& s) const {
            constexpr std::size_t est_size = estimate_size();
            char str[est_size];
            auto[p, ec] = std::to_chars(str, str + est_size, value);
            s += std::string_view(str, p - str);
        }

    private:
        const T& value;
    };

    template<typename T>
    struct FormatHelper<T, typename std::enable_if_t<
            std::is_same_v<std::string, decltype(std::declval<T>().format())>>> {
        explicit FormatHelper(const T& value) : value(value) {}
        static constexpr std::size_t estimate_size() {
            return 30;
        }

        void append_to(std::string& s) const {
            s += value.format();
        }

    private:
        const T& value;
    };

    template<typename T>
    typename std::enable_if_t<is_print<T>::value, std::string> make_string(const T &value) {
        FormatHelper<T> helper(value);  // Explicit!
        std::string formatted;
        formatted.reserve(helper.estimate_size());
        helper.append_to(formatted);
        formatted.shrink_to_fit();
        return formatted;
    }
}  // namespace format
