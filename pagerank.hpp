#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#undef abs

using namespace std;

struct node
{
    string page;
    set<node *> links;
    float pr;
    node(string p_) : page(p_), pr(0){};
    node(string p_, set<node *> l_) : page(p_), links(l_), pr(0){};
    void print()
    {
        cout << page << ",\t ";
        cout << pr << ",\t links: { ";
        for (auto l : links)
            cout << l->page << " ";
        cout << "}\n";
    }
};

class graph
{
  private:
    set<node *> g;

  public:
    void add_node(string p_)
    {
        node *n = new node(p_);
        g.insert(n);
    }
    void add_edge(string p1_, string p2_)
    {
        node *n1 = NULL, *n2 = NULL;
        for (auto p : g)
        {
            if (p->page == p1_)
            {
                n1 = p;
            }
            else if (p->page == p2_)
            {
                n2 = p;
            }
        }
        //Note, links are now a directed edges,
        //such that A is a link to  B,
        //but B is not necesarily a link to A.
        if (n1 && n2)
            n1->links.insert(n2);
    }
    set<node *> get_universe()
    {
        return g;
    }
    void print()
    {
        for (auto p : g)
            (*p).print();
    }
};

void page_rank(graph g)
{
    set<node *> u = g.get_universe();

    //map to hold future page ranks//
    map<node *, float> m;

    int N = u.size();
    float d = 0.85;
    float rp = (float)(1 - d) / N;
    float me = 0.09;

    for (auto p : u)
    {
        (*p).pr = (float)1 / N;
    }

    bool cf = true;
    while (cf)
    {
        m.clear();
        for (auto p : u)
        {
            for (auto l : (*p).links)
            {
                if ((*p).links.empty())
                    m[l] += (float)1 / N;
                else
                    m[l] += (float)p->pr / (*p).links.size();
            }
        }

        cf = false;
        for (auto p : u)
        {
            m[p] = rp + d * m[p];
            if (abs(m[p] - (*p).pr) > me)
                cf = true;
            (*p).pr = m[p];
        }
    }
}