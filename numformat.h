#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <set>
using namespace std;

namespace RegexNumber
{
    const string digits = "\\bone\\b|\\btwo\\b|\\bthree\\b|\\bfour\\b|\\bfive\\b|\\bsix\\b|\\bseven\\b|\\beight\\b|\\bnine\\b";
    const string teens = "(\\bten\\b|\\beleven\\b|\\btwelve\\b|\\bthirteen\\b|\\bfourteen\\b|\\bfifteen\\b|\\bsixteen\\b|\\bseventeen\\b|\\beighteen\\b|\\bnineteen\\b)";
    const string tens_prefix = "(\\btwenty-|\\bthirty-|\\bforty-|\\bfifty-|\\bsixty-|\\bseventy-|\\beighty-|\\bninety-)";
    const string tens_suffix = "(one\\b|two\\b|three\\b|four\\b|five\\b|six\\b|seven\\b|eight\\b|nine\\b)";
    const string tens_no_suffix = "(\\btwenty\\b|\\bthirty\\b|\\bforty\\b|\\bfifty\\b|\\bsixty\\b|\\bseventy\\b|\\beighty\\b|\\bninety\\b)";
    const string tens = "("+tens_prefix+tens_suffix+")|("+tens_no_suffix+")|("+teens+")|("+digits+")";
    const string hundreds = "(("+digits+") hundred and? ("+tens+"))|(("+digits+") hundred\\b)|("+tens+")";
    const string thousands = "(("+hundreds+") thousand ("+hundreds+"))|(("+hundreds+") thousand\\b)|("+hundreds+")";
    const string millions = "(("+thousands+") million ("+thousands+"))|(("+thousands+") million\\b)|("+thousands+")";
    const string number =  "(\\bone billion\\b)|("+millions+")|(\\bzero\\b)";
}

const map<string, int> numbers_value =
{
    {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, 
    {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10}, 
    {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15}, 
    {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, 
    {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50}, 
    {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90}, 
    {"hundred", 100}, {"thousand", 1000}, {"million", 1000000}, {"billion", 1000000000}
};

const set<string> big_numbers =
{
    "thousand", "million", "billion"
};

const int parseWrittenNumber(const string& str) 
{
    int total = 0;
    int prior = -1;

    string word;
    istringstream iss(str);
    while (getline(iss, word, ' '))
    {
        if (word == "and") continue;

        int v = 0;

        if (word.find("-") != word.npos)
        {
            const size_t pos_hyphen = word.find("-");
            v += numbers_value.at(word.substr(0, pos_hyphen));
            v += numbers_value.at(word.substr(pos_hyphen+1));
        }
        else if (numbers_value.find(word) != numbers_value.end())
        {
            v += numbers_value.at(word);
        }

        if (prior == -1) 
        {   
            prior = v;
        }
        else if (prior > v)
        {
            prior += v;
        }
        else 
        {
            prior *= v;
        }

        if (big_numbers.find(word) != big_numbers.end())
        {
            total += prior;
            prior = -1;
        }
    }

    total = (prior != -1) ? (total + prior) : (total);

    return total;
}

string formatNumbersOfText(string text)
{
    const regex re = regex(RegexNumber::number);
    smatch match_results;
    string text_formatted = "";
    while (regex_search(text, match_results, re)) 
    {
        text_formatted += match_results.prefix();
        text_formatted += to_string(parseWrittenNumber(match_results.str(0)));
        text = match_results.suffix().str();
    }
    text_formatted += text;

    return text_formatted;
}