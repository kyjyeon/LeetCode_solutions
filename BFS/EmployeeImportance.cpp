/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*>umap;//Used unordered_map to filter the employees vector
        for (auto& elem : employees) {//Use auto& to make more simple and lighter for loop
            umap[elem->id] = elem;
        }
        return getTotal(umap, id);
    }

    int getTotal(unordered_map<int, Employee*>& umap, int id) { //gets the sum of importance value
        int total = umap[id]->importance;
        for (auto& elem : umap[id]->subordinates) {
            total += getTotal(umap, elem); //recursive function to get the subordinates and the indirect subordinates importance
        }
        return total;
    }

};
