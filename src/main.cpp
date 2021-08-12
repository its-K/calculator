#include<iostream>
#include "add.h"
#include "sub.h"
#include "divide.h"
#include "multiply.h"
#include "sin.h"
#include "cos.h"
#include "log.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <fmt/core.h>
#include "boost/date_time/gregorian/gregorian.hpp"
#include <string>

using namespace rapidjson;

int main(int argc, char const *argv[])
{
    int op=0;
    while(true){
        fmt::print("1-Add\n2-Sub\n3-Multiply\n4-Divide\n5-Sin\n6-Cos\n7-Log\n");
        //std::cin >> op;
        op=9;
        if(op==9){
            break;
        }
        int a;
        int b;
        switch (op)
        {
        case 1:
            std::cin >> a >> b;
            std::cout << "Result\n";
            std::cout << add(a,b) << "\n";
            break;
        case 2:
            std::cin >> a >> b;
            std::cout << "Result\n";
            std::cout << sub(a,b) << "\n";
            break;
        case 3:
            std::cin >> a >> b;
            std::cout << "Result\n";
            std::cout << multiply(a,b) << "\n";
            break;
        case 4:
            std::cin >> a >> b;
            std::cout << "Result\n";
            std::cout << divide(a,b) << "\n";
            break;
        case 5:
            std::cin >> a;
            std::cout << "Result\n";
            std::cout << sin(a) << "\n";
            break;
        case 6:
            std::cin >> a;
            std::cout << "Result\n";
            std::cout << cos(a) << "\n";
            break;
        case 7:
            std::cin >> a ;
            std::cout << "Result\n";
            std::cout << log(a) << "\n";
            break;
        default:
            break;
        }
    }
    fmt::print("\nJSON\n");

    // 1. Parse a JSON string into DOM.
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);
 
    // 2. Modify it by DOM.
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);
 
    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
 
    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;

    fmt::print("Date\n");
    try {
    std::string si("2001-10-9"); //2001-October-09
    date d(from_simple_string(si));
    std::cout << to_simple_string(d) << std::endl;
    }
    catch(std::exception& e) {
      std::cout << "  Exception: " <<  e.what() << std::endl;
    }

    return 0;
}
