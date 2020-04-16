class Solution {
public:
    vector<string> fizzBuzz(int n)
    {
        vector <string> words;
        if(n < 1) return words;
        for(unsigned int i = 1; i <= n; i++)
        {
            if(i%3 == 0 && i%5 == 0)
            {
                words.push_back("FizzBuzz");
            }
            else if(i%3 == 0)
            {
                words.push_back("Fizz");
            }
            else if(i%5 == 0)
            {
                words.push_back("Buzz");
            }
            else
            {
                words.push_back(to_string(i));
            }
        }

        return words;
    }
};
