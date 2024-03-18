#include <RQuantLib.h>

#include <ql/event.hpp>
#include <ql/time/date.hpp>
#include <ql/time/daycounter.hpp>
#include <vector>

//' Print the date in `n` days from now
//' @export
// [[Rcpp::export]]
QuantLib::Date dateInDays(int n) {
    QuantLib::Date today = QuantLib::Date::todaysDate();
    QuantLib::Date res = today + n;
    return res;
}

//' @export
// [[Rcpp::export]]
double yearFrac(QuantLib::Date date1, QuantLib::Date date2) {
    QuantLib::DayCounter convention =
        QuantLib::ActualActual(QuantLib::ActualActual::ISDA);
    double res = convention.yearFraction(date1, date2);
    return res;
}

//' @export
// [[Rcpp::export]]
std::vector<QuantLib::Date> couponDates(QuantLib::Date start, QuantLib::Date maturity, int freq) {
    QuantLib::Schedule schedule =
        QuantLib::MakeSchedule()
            .from(start)
            .to(maturity)
            .withCalendar(QuantLib::TARGET())
            .withConvention(QuantLib::BusinessDayConvention::ModifiedFollowing)
            .withFrequency(static_cast<QuantLib::Frequency>(freq));
    return schedule.dates();
}

//' @export
// [[Rcpp::export]]
std::vector<double> daysBetween(std::vector<QuantLib::Date> dates) {
    std::vector<double> res(dates.size() - 1);
    for (int i = 1; i < dates.size(); i++) {
        res[i - 1] = dates[i] - dates[i - 1];
    }
    return res;
}