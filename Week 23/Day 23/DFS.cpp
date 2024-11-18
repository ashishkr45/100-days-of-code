//// Implementing DFS Traversal
#include<iostream>
using namespace std;
class Graph
{
	private:
		int **a;
		int n;
		int e;
		int *visited;
	public:
		Graph(int vertices, int edges);
		~Graph();
		bool isEmpty();
		int NumberOfVertices();
		int NumberOfEdges();
		int Degree(int u);
		bool EdgeExists(int u, int v);
		void InsertEdge(int u, int v);
		void DeleteEdge(int u, int v);
		void DisplayAdjMatrix();
		void DFS(int);


};

Graph::Graph(int vertices, int edges)
{
			n=vertices;
			e=edges;
			a=new int*[n+1];
			for(int i=1;i<=n;i++)
				a[i]=new int[n+1];
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					a[i][j]=0;
				}
			}
			visited=new int[n+1];
			for(int i=1;i<=n;i++)
				visited[i]=0;
}

Graph::~Graph()
{
	delete [] a;
	delete [] visited;
}

void Graph::DFS(int v)
{
	visited[v]=1;
	int w;
	for(int i=1;i<=n;i++)
	{
		if(a[v][i]==1 && visited[i]==0)
		{
			///w is found such that it is adj and not visited yet
			w=i;
			cout<<w<<"\t";
			visited[w]=1;
			DFS(w);
		}
	}
}
bool Graph::isEmpty()
{
	return n==0;
}
int Graph::NumberOfVertices()
{
	return n;
}
int Graph::NumberOfEdges()
{
	return e;
}
int Graph::Degree(int u)
{
	int sum=0;
	for(int j=1;j<=n;j++)
		sum=sum+a[u][j];///row sum
	return sum;
}
bool Graph::EdgeExists(int u, int v)
{
	if(u<1 || u>n || v<1 || v>n )
		cout<<"Bad Input, No such Element in Vertex Set";
	if(a[u][v]==1)
		return true;
	return false;
}
void Graph::InsertEdge(int u, int v)
{
	if(u<1 || u>n || v<1 || v>n || a[u][v]==1)
		cout<<"Bad Input, No such Element in Vertex Set";
	a[u][v]=1;
	a[v][u]=1;
}
void Graph::DeleteEdge(int u, int v)
{
	if(u<1 || u>n || v<1 || v>n || a[u][v]==0)
		cout<<"Bad Input, No such Element in Vertex Set";
	a[u][v]=0;
}
void Graph::DisplayAdjMatrix()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<"   ";
		}
		cout<<"\n";
	}
}

int main()
{
		int n,e,u,v;
		cout<<"\nEnter the number of vertex in the Graph\n";
		cin>>n;
		cout<<"\nEnter the number of distinct unordered pairs\n";
		cin>>e;
		Graph g(n,e);
		for(int i=1;i<=e;i++)
		{
			cout<<"\nEnter the Vertex u of Edge " <<i<<"\n";
			cin>>u;
			cout<<"\nEnter the Vertex V of Edge "<<i<<"\n";
			cin>>v;
			g.InsertEdge(u,v);
		}
		cout<<"\nThe Adjacency Matrix of G is *********\n";
		g.DisplayAdjMatrix();
		cout<<"\n The Depth First Search Traversal of Graph is ......\n";
		cout<<"1\t";
		g.DFS(1);


		return 0;

}