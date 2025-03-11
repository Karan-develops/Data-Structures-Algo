#include <iostream>
#include <cstring>
using namespace std;
// 1. Returning a string literal (Safe)
const char* getStringLiteral(){
    return "Hello, World!";
}

// 2. Returning a local char array (Unsafe - Avoid this)
char* getLocalArray(){
    char str[] = "Local"; // ❌ This will cause undefined behavior
    return str;
}

// 3. Using static (Safe)
char* getStaticString(){
    static char str[]="Static String";
    return str;
}

// 4. Using new (Dynamic Allocation - Requires delete[])
char* getDynamicString(){
    char* str=new char[12];  
    strcpy(str,"Dynamic Str");
    return str;  // ✅ Caller must delete[]
}

// 5. Using std::string and .c_str()
std::string getStringObject(){
    return "String Object";
}

int main(){
    // Example 1: String literal
    cout<<"String Literal: "<<getStringLiteral()<<endl;

    // Example 2: Local array (Undefined behavior, should be avoided)
    cout<<"Local Array: "<<getLocalArray()<<" (May crash or print garbage)"<<endl;

    // Example 3: Static memory
    cout<<"Static String: "<<getStaticString()<<endl;

    // Example 4: Dynamic Allocation
    char* dynamicStr=getDynamicString();
    cout<<"Dynamic String: "<<dynamicStr<<endl;
    delete[] dynamicStr;  // Important to prevent memory leak

    // Example 5: Using std::string
    cout<<"String Object: "<<getStringObject().c_str()<<endl;
    return 0;
}
