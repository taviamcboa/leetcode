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
        unordered_map<int, Employee*> emp_hashmap; 

        for(int i = 0; i < employees.size(); i++){
            emp_hashmap[employees[i]->id] = employees[i]; 
        }

        return dfs(emp_hashmap, id); 
    }

private: 
    int dfs(unordered_map<int, Employee*>& hashmap, int id){
        int result; 

        const Employee* current = hashmap[id]; 
        result += current->importance; 

        for(int i = 0; i < current->subordinates.size(); i++){
            result += dfs(hashmap,  current->subordinates[i]); 
        }

        return result; 
    }
};