
#include <map>
#include <string>
#include <optional>
#include <memory>
using namespace std;


struct File{
    optional <string> content=nullopt;
    map<string, shared_ptr<File>> files;
};


class FileSystem {
public:
    FileSystem() {
        root = make_shared<File>();
    }
    
    vector<string> ls(string path) {
        // Standardize input.
        if(path.back() == '/'){
            path.pop_back();
        }
        // When path is not "/"
        shared_ptr<File> curr_path = root;
        size_t idx = 1;
        string name;
        while(idx < path.size()){
            const auto delimiter_idx = path.find('/', idx);
            if(delimiter_idx == string::npos){
                name = path.substr(idx);
            }else{
                name = path.substr(idx, delimiter_idx -idx);
            }
            curr_path = curr_path->files[name];
            if(delimiter_idx == string::npos){
                break;
            }
            idx = delimiter_idx + 1;
           
        }
        // The input path is a file.
        if(curr_path->content.has_value()){
            return {name};
        }
        std::vector<string> files;
        for(const auto&[file, ptr]:curr_path->files){
            files.push_back(file);
        }
        sort(files.begin(), files.end());
        return files;
    }
    
    void mkdir(string path) {
         // Standardize input.
        if(path.back() == '/'){
            path.pop_back();
        }
        shared_ptr<File> curr_path = root;
        size_t idx = 1;
        string name;
        while(idx < path.size()){
            const auto delimiter_idx = path.find('/', idx);
            if(delimiter_idx == string::npos){
                name = path.substr(idx);
            }else{
                name = path.substr(idx, delimiter_idx -idx);
            }
            if(curr_path->files.find(name) == curr_path->files.end()){
                curr_path->files[name] = make_shared<File>();
            }
            curr_path = curr_path->files[name];
            if(delimiter_idx == string::npos){
                break;
            }
            idx = delimiter_idx + 1;
        }
    }
    
    void addContentToFile(string filePath, string content) {
       shared_ptr<File> curr_path = root;
        size_t idx = 1;
        string name;
        while(idx < filePath.size()){
            const auto delimiter_idx = filePath.find('/', idx);
            if(delimiter_idx == string::npos){
                name = filePath.substr(idx);
            }else{
                name = filePath.substr(idx, delimiter_idx -idx);
            }
            // This should only occur at the very end.
            if(curr_path->files.find(name) == curr_path->files.end()){
                curr_path->files[name] = make_shared<File>();
            }
            curr_path = curr_path->files[name];
            if(delimiter_idx == string::npos){
                break;
            }
            idx = delimiter_idx + 1;
        }
        curr_path->content = curr_path->content.has_value()? curr_path->content.value() + content: content;

    }
    
    string readContentFromFile(string filePath) {
        shared_ptr<File> curr_path = root;
        size_t idx = 1;
        string name;
        while(idx < filePath.size()){
            const auto delimiter_idx = filePath.find('/', idx);
             if(delimiter_idx == string::npos){
                name = filePath.substr(idx);
            }else{
                name = filePath.substr(idx, delimiter_idx -idx);
            }
            string name = filePath.substr(idx, delimiter_idx-idx);
            // Good place to add error handling if needed.
            if(curr_path->files.find(name) == curr_path->files.end()){
                curr_path->files[name] = make_shared<File>();
            }
            curr_path = curr_path->files[name];
            if(delimiter_idx == string::npos){
                break;
            }
            idx = delimiter_idx + 1;
        }
        return curr_path->content.has_value()? curr_path->content.value(): "";
    }

private:
    shared_ptr<File> root;

};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */