#include <iostream>
#include <string>
#include <list>

using namespace std;

//NFA datastructure
struct State;
struct Edge
{
	char mTake;
	State* mTo;

	Edge(char c, State* t)
	{
		mTake = c;
		mTo = t;
	}
};

struct State
{
	bool mFinish;
	list<Edge> mEdges;

	State(): mFinish(false) {}
	void AddEdge(Edge e)
	{
		mEdges.push_back(e);
	}
};


//recursion match
bool walk(State* state, string s)
{
    if(s.length() == 0)
    {
        if(state->mFinish) { return true;}
        else if(state->mEdges.size() == 0) { return false;}
    }
    for(const auto &e: state->mEdges)
    {
        if(e.mTake == '\0')
        {
            if( walk(e.mTo, s)) { return true;}
        }
        else if(s.length() > 0 )
        {
            if(e.mTake == '.' || e.mTake == s[0])
            {
                if(walk(e.mTo, s.substr(1))) { return true;}
            }
        }
    }
    return false;
}

bool isMatch(string s, string p)
{
	State* start = new State();
	State* pre = start;
	//构建一个NFA
	for(int i = 0; i < p.length(); ++i)
	{

		if((i+1) < p.length() && p[i + 1] == '*')
		{
			State* s1 = new State();
			State* s2 = new State();
			State* s3 = new State();
			pre->AddEdge(Edge('\0', s1));
			pre->AddEdge(Edge('\0', s3));
			s1->AddEdge(Edge(p[i], s2));
			s2->AddEdge(Edge('\0', s1));
			s2->AddEdge(Edge('\0', s3));
			pre = s3;
			++i;
		}
		else
		{
			State* s = new State();
			pre->AddEdge(Edge(p[i], s));
			pre = s;
		}
	}
	pre->mFinish = true;

	return walk(start, s);
}

int main()
{
	string s = "aaa";
	string p = "a*";
	cout << (isMatch(s, p)? "match": "not match") << endl;
	return 0;
}
