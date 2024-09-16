#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    char *str; // Pointer to the character array
    int length; // Length of the string
    // Helper function to create a string from another string
    void CreateString(const String& other){
        int otherLength = other.length;
        this->str = new char[otherLength + 1];
        for (int i = 0; i < otherLength; i++){
            this->str[i] = other.str[i];
        }
        this->str[otherLength] = '\0';
        this->length = otherLength;
    }
public:
    // Default constructor
    String():str(nullptr), length(0) {};
    // Constructor from C-string
    String(const char *str);
    // Copy constructor
    String(const String &str) { CreateString(str); };
    // Destructor
    ~String();
    // Print the string
    void Print();
    // Assignment operator
    String& operator=(const String &other);
    // Equality operator
    bool operator==(const String &other) const;
    // Concatenation operator
    String operator+(const String &other) const;
    // Output stream operator
    friend ostream& operator<<(ostream& out, const String &s);
    // Index operator
    char& operator[](const int index);
    // Get the length of the string
    int Length() const{ return length; }
};

// Constructor from C-string
String::String(const char *str){
    this->length = strlen(str);
    this->str = new char[length + 1];
    for (int i = 0; i < length; i++){
        this->str[i] = str[i];
    }
    this->str[length] = '\0';
}

// Destructor
String::~String(){
    delete[] str;
}

// Print the string
void String::Print(){
    if (str != nullptr){
        cout << str << "\n";
    } else {
        cout << "";
    }
}

// Assignment operator
String &String::operator=(const String &other){
    if (this == &other){
        return *this;
    }
    delete[] this->str;
    CreateString(other);
    return *this;
}

// Concatenation operator
String String::operator+(const String &other) const{
    int otherLength = other.length;
    int Length = this->length + otherLength;
    String newStr;
    newStr.str = new char[Length + 1];
    int i = 0;
    for (; i < this->length; i++){
        newStr.str[i] = this->str[i];
    }
    for (int j = 0; j < otherLength; j++, i++){
        newStr.str[i] = other.str[j];
    }
    newStr.str[Length] = '\0';
    newStr.length = Length;
    return newStr;
}

// Equality operator
bool String::operator==(const String &other) const{
    int otherLength = strlen(other.str);
    if (this->length != otherLength) return false;
    for (int i = 0; i < this->length; i++){
        if (this->str[i] != other.str[i]){
            return false;
        }
    }
    return true;
}

// Output stream operator
ostream& operator<<(ostream& out, const String &s){
    if (s.str != nullptr){
        out << s.str;
    }
    return out;
}

// Index operator
char &String::operator[](const int index){
    if (index >= this->length || index < 0){
        throw out_of_range("Out of range");
    }
    return this->str[index];
}
int main()
{
    String str("dfkfl;asf");
    String str2("worsdld23");
    String str3(str);
    cout << str[5] << '\n';
    str2[5] = 'Q';
    cout << str2 << '\n';
    cout << str3 << '\n';
    cout << (str == str2) << '\n';
    String res = str + str2 + str3 + "999999999";
    cout << res << '\n';

    return 0;
}
