// class Solution {
// public:
//     int numUniqueEmails(vector<string>& emails) {
//          unordered_set<string> uniqueEmails; // A set to store unique email addresses

//         // Iterate through each email in the input vector
//         for (string email : emails) {
//             int atIndex = email.find('@'); // Find the index of '@' in the email
//             string local = email.substr(0, atIndex); // Extract the local part (before '@')
//             string domain = email.substr(atIndex); // Extract the domain part (after '@')

//             // Find the index of '+' in the local part
//             int plusIndex = local.find('+');
//             if (plusIndex != string::npos) { // If '+' is found
//                 local = local.substr(0, plusIndex); // Keep only the part before '+'
//             }

//             // Remove all '.' characters from the local part
//             local.erase(remove(local.begin(), local.end(), '.'), local.end());

//             // Combine the processed local part with the domain part
//             uniqueEmails.insert(local + domain); // Add the formatted email to the set
//         }

//         // Return the total count of unique email addresses
//         return uniqueEmails.size();
//     }
// };

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails; // A set to store unique email addresses

        for(string email : emails) {
            string cleanEmail = "";

            for(char ch : email){
                if(ch == '+' || ch == '@') break;
                if(ch == '.') continue;

                cleanEmail += ch;
            }

            string domainName;

            for(int i = email.size()-1; i >=0; --i) {
                char currentChar = email[i];
                domainName += currentChar;
                if(currentChar == '@') break;
            }

            reverse(domainName.begin(), domainName.end());
            cleanEmail += domainName;
            uniqueEmails.insert(cleanEmail);
        }
        
        // Return the total count of unique email addresses
        return uniqueEmails.size();
    }
};
