#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string m_path;
        int  m_levels;
        int  m_pos[250];

        void up_level() {
            if (m_levels == 0) return;
            m_levels--;
            m_path.erase(m_path.length() - m_pos[m_levels]);
        }

        void record(string identifier) {
            m_path.append(identifier + '/');
            m_pos[m_levels] = identifier.length() + 1;
            m_levels++;
        }

        string simplifyPath(string path) {
            int old_pos = 1;
            int new_pos;
            string tmp;
            m_levels = 0;
            m_path = "";
            do {
                new_pos = path.find_first_of('/', old_pos);
                tmp = path.substr(old_pos, new_pos-old_pos);
                old_pos = new_pos + 1;
                if (tmp == "..")
                    up_level();
                else if (tmp == "" || tmp == ".") {
                    continue;
                } else
                    record(tmp);
            } while(new_pos != path.npos);
                
            return '/' + m_path.substr(0, m_path.length() - 1);
        }
};

int main(int argc, char *argv[]) {
    class Solution sol1;
    cout << sol1.simplifyPath("/test/google/") << endl;
    cout << sol1.simplifyPath("/test//google/") << endl;
    cout << sol1.simplifyPath("/test/./google/") << endl;
    cout << sol1.simplifyPath("/test/../google/") << endl;
    cout << sol1.simplifyPath("/test/google") << endl;
    cout << sol1.simplifyPath("//") << endl;
    cout << sol1.simplifyPath("/../") << endl;

    return 0;
}

