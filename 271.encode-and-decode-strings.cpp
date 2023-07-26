#include <vector>
#include <string>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded_string = "";
        for(const auto& str:strs){
            encoded_string += to_string(str.size())+ DELIMITER + str;
        }
        return encoded_string;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded_strings;
        // Points at curr idx looking into the string s.
        size_t idx = 0;
        while(idx < s.size()){
            size_t delimiter_pos = s.find_first_of(DELIMITER, idx);
            assert(delimiter_pos!=string::npos);
            // Get the length of original string.
            int length = stoi(s.substr(idx, delimiter_pos-idx));

            decoded_strings.push_back(s.substr(delimiter_pos+1, length));
            idx =delimiter_pos  + 1 + length;
        }
        return decoded_strings;
    }

private:
    const char DELIMITER ='#';
};