#ifndef INEXOR_UTIL_STRING_FORMATTER_HEADER
#define INEXOR_UTIL_STRING_FORMATTER_HEADER

#include <sstream>
#include <string>

namespace inexor {
namespace util {

  /// Format strings with a one-liner.
  ///
  /// This class can be used to quickly construct strings:
  ///
  ///   std::string foo = fmt << "Hello, we are he "
  ///       << "five" << "illuminati!! " << 5 << std::endl;
  ///   // => "Hello, we are the five illuminati!! 5\n"
  ///
  /// TODO: Move semantics?
  class StringFormatter {
  protected:

    std::ostringstream sbuf;

    StringFormatter() {}

    StringFormatter(const StringFormatter& other) :
        sbuf(other.sbuf.str()) {}

  public:
    /// @see fmt
    class FmtMark {
    public:
      template <typename T>
      StringFormatter operator<<(T s) {
        StringFormatter f;
        f << s;
        return f;
      }
    };

    template <typename T>
    StringFormatter& operator<<(T s) {
      sbuf << s;
      return *this;
    }

    operator std::string() {
      return sbuf.str();
    }
  };

  /// Marker that starts formatting a string
  /// @see StringFormatter
  extern StringFormatter::FmtMark fmt;
}
}

#endif
