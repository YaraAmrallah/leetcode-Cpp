class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        if(S == T) return true;
        int index;
        while(S.find_first_of('#') != std :: string :: npos)
        {
            index = S.find_first_of('#');
            if (index != 0) S.erase(index-1, 2);
            else S.erase(index,1);
        }

        while(T.find_first_of('#') != std :: string :: npos)
        {
            index = T.find_first_of('#');
            if (index != 0) T.erase(index-1, 2);
            else T.erase(index,1);
        }

        if(T == S) return true;

        return false;
    }
};
