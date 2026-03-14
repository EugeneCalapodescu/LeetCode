/*
    LeetCode 224

    The fastest answers use a stack

    This use the a grammer for the expressions, so can be extended to handle multiplications, powers, functions, variables, etc

    Expr:   Term [+ Term]
        :   Term [- Term]
        ;
    Term:   Factor [* Factor]
        :   Factor [/ Factor]
        ;
    Factor: ( Expr )
        :   - Factor
        :   [0-9]*
        ;

    Ref: Compilers (Dragon Book) Aho Sethi Ullman

    TODO:   the next token is always read, then need to be pushed back sometime
            perhaps simpler to understand if we had two functions, one to peek, the second one to scan



*/

#include "..\tools.h"


static double calculate(std::string s);

static std::string next_token(const std::string& input, int& pos);
static double compute_expr(const std::string& s, int& start);
static double compute_term(const std::string& s, int& start);
static double compute_factor(const std::string& s, int& start);

void lc_0224()
{
    std::cout << "Enter an expression, e.g. (1+2)/-3+4\n";

    std::string line;

    do
    {
        printf("> ");
        std::getline(std::cin, line);
        printf("%f\n", calculate(line));
    } while (!line.empty());

}

std::string next_token(const std::string& input, int& pos)
{
    auto n = input.size();

    if (pos >= n)
        return std::string();

    while (input[pos] == ' ' && pos < n)
        pos++;

    if (pos >= n)
        return std::string();

    if (!isdigit(input[pos])) // +, -, *, /
        return input.substr(pos++, 1);

    int start = pos;
    while (isdigit(input[pos]))
        pos++;

    return input.substr(start, pos - start);
}


double compute_expr(const std::string& s, int& start)
{
    double term = compute_term(s, start);

    int save = start;
    std::string token = next_token(s, start);

    while (token == "+" || token == "-")
    {
        if (token == "+")
            term += compute_term(s, start);
        else if (token == "-")
            term -= compute_term(s, start);

        save = start;
        token = next_token(s, start);
    }

    start = save;
    return term;
}

double compute_term(const std::string& s, int& start)
{
    double factor = compute_factor(s, start);

    int save = start;
    std::string token = next_token(s, start);

    while (token == "*" || token == "/")
    {
        if (token == "*")
            factor *= compute_factor(s, start);
        else if (token == "/")
            factor /= compute_factor(s, start);

        save = start;
        token = next_token(s, start);
    }

    start = save;
    return factor;
}

double compute_factor(const std::string& s, int& start)
{
    std::string token = next_token(s, start);

    if (token == "(")
    {
        double expr = compute_expr(s, start);
        token = next_token(s, start);

        if (token != ")")
            printf("Expecting closing parenthesis\n");

        return expr;
    }

    if (token == "-")
    {
        int save = start;
        std::string test = next_token(s, start);

        if (isdigit(test[0]))
            return -atoi(test.c_str());

        start = save;
        return -compute_factor(s, start);
    }

    return atoi(token.c_str());
}


double calculate(std::string s) {
    int i = 0;
    return compute_expr(s, i);
}
