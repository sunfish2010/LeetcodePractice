#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> src_dst_map;
        unordered_map<string, vector<bool>> src_visited_map;
        for(const auto& ticket: tickets){
            src_dst_map[ticket[0]].push_back(ticket[1]);
        }
        // Sort the destination in lexical order for greedy, and construct a visit map.
        for(auto &[src, dsts]: src_dst_map){
            sort(dsts.begin(), dsts.end());
            src_visited_map[src] = vector<bool>(dsts.size(), false);
        }
        length = tickets.size() + 1;
        vector<string> iter = {"JFK"};
        if(find_itinerary(src_dst_map, src_visited_map, iter)){
            return iter;
        }
        return {};

    }
private:
    bool find_itinerary(const unordered_map<string, vector<string>> &src_dst_map,  
    unordered_map<string, vector<bool>> &src_visited_map, vector<string>& iter){
        if(iter.size() == length){
            return true;
        }
        const auto src = iter.back();
        if(!src_dst_map.count(src)){
            return false;
        }
        const auto& dsts = src_dst_map.at(src);
        for(int i = 0; i < dsts.size(); ++i){
            if(src_visited_map[src][i]){
                continue;
            }
            iter.push_back(dsts[i]);
            src_visited_map[src][i] = true;
            if(find_itinerary(src_dst_map, src_visited_map, iter)){
                return true;
            }
            iter.pop_back();
            src_visited_map[src][i] = false;
        }
        return false;
    }
    
    int length;
};