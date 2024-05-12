#include <string>
#include <iostream>

int main() {
    std::string values;
    std::getline(std::cin, values);

    std::string templateString;
    std::getline(std::cin, templateString);

    // Put values into template
    // values format: "person=Paul,action=strolls around,place=the park"
    // template format: "[person] [action] [place]"
    // result: "Paul strolls around the park"
    std::string result;

    // split values into pairs
    std::string delimiter = ",";
    size_t pos = 0;

    while ((pos = values.find(delimiter)) != std::string::npos) {
        std::string pair = values.substr(0, pos);
        size_t equalPos = pair.find("=");
        std::string key = pair.substr(0, equalPos);
        std::string value = pair.substr(equalPos + 1);
        values.erase(0, pos + delimiter.length());

        // replace key with value in template
        size_t keyPos = templateString.find("[" + key + "]");
        if (keyPos != std::string::npos) {
            templateString.replace(keyPos, key.length() + 2, value);
        }
    }

    // last pair
    size_t equalPos = values.find("=");
    std::string key = values.substr(0, equalPos);
    std::string value = values.substr(equalPos + 1);

    // replace key with value in template
    size_t keyPos = templateString.find("[" + key + "]");
    if (keyPos != std::string::npos) {
        templateString.replace(keyPos, key.length() + 2, value);
    }

    std::cout << templateString << std::endl;

    return 0;
}