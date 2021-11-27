#ifndef PATCH_FILE_INFO_H_
#define PATCH_FILE_INFO_H_

#include <string>
#include <set>


class PatchFileInfo {
public:
  PatchFileInfo(const std::string& name) : _name(name) {};
  virtual ~PatchFileInfo() {};
  
  void addLine(unsigned line) {
    _changed_lines.insert(line);
  }
  
  bool containsLine(unsigned line) const {
    return (_changed_lines.count(line) > 0);    
  }
  
  bool empty() const {
    return _changed_lines.empty();
  }
  
  
private:  
  std::string _name;
  std::set<unsigned> _changed_lines;
};




#endif /* PATCH_FILE_INFO_H_ */