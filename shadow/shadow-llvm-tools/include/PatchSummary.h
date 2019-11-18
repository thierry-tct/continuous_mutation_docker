#ifndef PATCH_SUMMARY_H_
#define PATCH_SUMMARY_H_

#include "PatchFileInfo.h"

#include <string>
#include <map>


class PatchSummary {
public:
  PatchSummary() {};
  virtual ~PatchSummary() {
    for (std::map<std::string, PatchFileInfo*>::iterator it = _files.begin(), ite = _files.end(); it != ite; ++ it) {
      if (it->second) {
	delete it->second;
	it->second = NULL;
      }
    }
  }
  
  void addFile(const std::string& filename, const std::set<unsigned>& line_numbers) {
    assert(_files.find(filename) == _files.end());
    PatchFileInfo* info = new PatchFileInfo(filename);
    assert(info);
    for (std::set<unsigned>::const_iterator it = line_numbers.begin(), ite = line_numbers.end(); it != ite; ++it) {
      info->addLine(*it);
    }    
  }
  
  bool inPatch(const std::string& filename) const {
    std::map<std::string, PatchFileInfo*>::const_iterator it = _files.find(filename);
    return (it != _files.end() && it->second && !it->second->empty());
  }
  
  bool inPatch(const std::string& filename, unsigned line) const {
    bool res = false;
    std::map<std::string, PatchFileInfo*>::const_iterator it = _files.find(filename);
    if (it != _files.end()) {
      PatchFileInfo* info = it->second;
      if (info) {
	res = info->containsLine(line);
      }
    }
    return res;
  }
  
  
  
private:  
  std::map<std::string, PatchFileInfo*> _files;
};




#endif /* PATCH_SUMMARY_H_ */