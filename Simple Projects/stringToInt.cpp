#include <iostream>
#include <string>
#include <map>
#include <cctype>

std::string alpha_to_int(char alpha);
std::string alphabet_position(const std::string &text);

int main() {

    std::string text;

    std::cout << "Alphabet Text to Numbers: ";
    std::getline(std::cin, text);

    std::cout << alphabet_position(text);

    return 0;
}

std::string alphabet_position(const std::string &text) {
  
  std::string returnStr = "";
  
  for(int i = 0; i < text.length(); i++) {
    if(alpha_to_int(text[i]) == "-1") {
        continue;
    }
    returnStr += alpha_to_int(text[i]) + ' ';
  }
  returnStr.pop_back();
  
  return returnStr;
}

std::string alpha_to_int(char alpha) {
  
  alpha = tolower(alpha);
  std::string str;

    switch (alpha) {
        case 'a': str = "1"; break;
        case 'b': str = "2"; break;
        case 'c': str = "3"; break;
        case 'd': str = "4"; break;
        case 'e': str = "5"; break;
        case 'f': str = "6"; break;
        case 'g': str = "7"; break;
        case 'h': str = "8"; break;
        case 'i': str = "9"; break;
        case 'j': str = "10"; break;
        case 'k': str = "11"; break;
        case 'l': str = "12"; break;
        case 'm': str = "13"; break;
        case 'n': str = "14"; break;
        case 'o': str = "15"; break;
        case 'p': str = "16"; break;
        case 'q': str = "17"; break;
        case 'r': str = "18"; break;
        case 's': str = "19"; break;
        case 't': str = "20"; break;
        case 'u': str = "21"; break;
        case 'v': str = "22"; break;
        case 'w': str = "23"; break;
        case 'x': str = "24"; break;
        case 'y': str = "25"; break;
        case 'z': str = "26"; break;
        default: return "-1";
    }
  
  return str;
}