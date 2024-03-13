#include <RQuantLib.h>
#include <ql/time/date.hpp>
#include <ql/event.hpp>

//' @export
// [[Rcpp::export]]
QuantLib::Date rquantlib_test() {
    QuantLib::Date date(QuantLib::Day(13), QuantLib::Month(3), QuantLib::Year(2024));
    return date;
}