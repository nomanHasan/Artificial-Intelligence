#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;


class Node{
public:
	char data;
	vector<Node> edgeNodes;
	int pathCost;

	Node(char d){
		data = d;
		pathCost = 0;
	}

	void addEdgeNodes(Node n){
		
		edgeNodes.push_back(n);
	}
	int getCost(){
		return pathCost;
	}
	void setCost(int cost){
		pathCost = cost;
	}

};

class Graph{
public:
	vector<Node> allNodes;

	void push_back(Node n){
		allNodes.push_back(n);
	}

	bool contains(char n){
		for (int i = 0; i < allNodes.size(); i++){
			if (n == allNodes[i].data){
				return true;
			}
		}
		return false;
	}

	Node getNode(char n){
		for (int i = 0; i < allNodes.size(); i++){
			if (n == allNodes[i].data){
				return allNodes[i];
			}
		}
		Node null('x');
		return null;
	}
};

class Queue{

public:
	list <Node> allNodes;

	void pop(){
		allNodes.pop_front();
	}

	void pop_stack(){
		allNodes.pop_back();
	}

	Node getFront(){
		Node n = allNodes.front();
		return n;
	}

	Node getBack(){
		Node n = allNodes.back();
		return n;
	}

	void push(Node n){
		allNodes.push_back(n);
	}

	bool contains(char n){
		for (std::list<Node>::const_iterator iterator = allNodes.begin(), end = allNodes.end(); iterator != end; iterator++) {
			
			if (iterator->data == n){
				return true;
			}
		}
		return false;
	}

	

};


class PriorityQueue{

public:
	list<Node> allNodes;

	void pop(){
		allNodes.pop_front();
	}

	void pop_stack(){
		allNodes.pop_back();
	}

	Node getFront(){
		Node n = allNodes.front();
		return n;
	}

	Node getBack(){
		Node n = allNodes.back();
		return n;
	}

	void push(Node n){

		if (allNodes.size() >= 1){
			for (std::list<Node>::const_iterator iterator = allNodes.begin(), end = allNodes.end(); iterator != end; iterator++) {
				//cout << iterator->pathCost << " > " << n.getCost() << " ? " << endl;
				if (iterator->pathCost>n.getCost()){

					//cout << iterator->pathCost << " > " << n.getCost() << " YES " << endl;

					allNodes.insert(iterator, n);
					return;
				}
			}
			allNodes.push_back(n);
			//cout << "PUSHED " << n.data << " cost " << n.getCost() << endl;
		}
		else if (allNodes.size() == 0){
			allNodes.push_back(n);
		}
	}

	bool contains(char n){
		for (std::list<Node>::const_iterator iterator = allNodes.begin(), end = allNodes.end(); iterator != end; iterator++) {
			if (iterator->data == n){
				return true;
			}
		}
		return false;
	}


	int getSize(){
		return allNodes.size();
	}

};



Graph inputGraphAuto(Graph graph){
	Node n1('A');
	Node next1('P');
	n1.addEdgeNodes(next1);
	Node next2('W');
	n1.addEdgeNodes(next2);
	graph.push_back(n1);


	Node n2('P');
	Node next3('A');
	n2.addEdgeNodes(next3);
	Node next4('L');
	n2.addEdgeNodes(next4);
	Node next5('O');
	n2.addEdgeNodes(next5);
	graph.push_back(n2);

	Node n3('W');
	Node next6('A');
	n3.addEdgeNodes(next6);
	Node next7('R');
	n3.addEdgeNodes(next7);
	Node next8('U');
	n3.addEdgeNodes(next8);
	graph.push_back(n3);

	Node n4('L');
	Node next81('P');
	n4.addEdgeNodes(next81);
	Node next9('M');
	n4.addEdgeNodes(next9);
	graph.push_back(n4);

	Node n5('O');
	Node next10('P');
	n5.addEdgeNodes(next10);
	Node next11('M');
	n5.addEdgeNodes(next11);
	graph.push_back(n5);

	Node n6('R');
	Node next12('M');
	n6.addEdgeNodes(next12);
	Node next13('W');
	n6.addEdgeNodes(next13);
	graph.push_back(n6);

	Node n7('U');
	Node next14('M');
	n7.addEdgeNodes(next14);
	Node next15('W');
	n7.addEdgeNodes(next15);
	graph.push_back(n7);

	Node n8('M');
	Node next16('L');
	n8.addEdgeNodes(next16);
	Node next17('O');
	n8.addEdgeNodes(next17);
	Node next28('R');
	n8.addEdgeNodes(next28);
	Node next19('U');
	n8.addEdgeNodes(next19);
	graph.push_back(n8);

	return graph;
}


Graph inputGraphUCS(Graph graph){
	Node n1('A');
	Node next1('D');
	next1.setCost(3);
	n1.addEdgeNodes(next1);
	Node next2('B');
	next2.setCost(5);
	n1.addEdgeNodes(next2);
	graph.push_back(n1);


	Node n2('B');
	Node next3('C');
	next3.setCost(1);
	n2.addEdgeNodes(next3);
	graph.push_back(n2);

	Node n3('C');
	Node next6('E');
	next6.setCost(6);
	n3.addEdgeNodes(next6);
	Node next7('G');
	next7.setCost(8);
	n3.addEdgeNodes(next7);
	graph.push_back(n3);

	Node n4('D');
	Node next81('E');
	next81.setCost(2);
	n4.addEdgeNodes(next81);
	Node next82('F');
	next82.setCost(2);
	n4.addEdgeNodes(next82);
	graph.push_back(n4);

	Node n5('E');
	Node next10('B');
	next10.setCost(4);
	n5.addEdgeNodes(next10);
	graph.push_back(n5);

	Node n6('F');
	Node next12('G');
	next12.setCost(3);
	n6.addEdgeNodes(next12);
	graph.push_back(n6);

	Node n7('G');
	Node next14('E');
	next14.setCost(4);
	n7.addEdgeNodes(next14);
	graph.push_back(n7);

	return graph;
}

void outputGraph(Graph graph){
	cout << "Outputting the Graph" << endl;

	for (int i = 0; i < graph.allNodes.size(); i++){
		cout << graph.allNodes[i].data << " -> ";
		for (int j = 0; j < graph.allNodes[i].edgeNodes.size(); j++){
			cout << graph.allNodes[i].edgeNodes[j].data << " ";
		}
		cout << endl;
	}
}

vector<Node> traverseBFS(Graph graph){

	vector<Node> traversal;

	cout << "BFS Traversing Analysing ......" << endl;
	Queue queue;

	Queue visited;

	queue.push(graph.allNodes[0]);
	visited.push(graph.allNodes[0]);

	while (!queue.allNodes.empty()){

		Node mNode = queue.getFront();		//Getting the first element of the queue
		queue.pop();						//Deleting the First element of the queue
		traversal.push_back(mNode);


		for (int j = 0; j < mNode.edgeNodes.size(); j++){
			char ch = mNode.edgeNodes[j].data;
			if (!queue.contains(ch) && !visited.contains(ch)){
				Node n = graph.getNode(ch);
				visited.push(n);
				queue.push(n);
			}

		}
	}

	return traversal;
}

vector<Node> traverseDFS(Graph graph){
	vector<Node> Dtraversal;

	cout << "DFS Traversing Analysing ......" << endl;
	Queue Dqueue;

	Queue Dvisited;

	Dqueue.push(graph.allNodes[0]);
	Dvisited.push(graph.allNodes[0]);

	while (!Dqueue.allNodes.empty()){

		Node mNode = Dqueue.getBack();		//Getting the first element of the queue
		Dqueue.pop_stack();						//Deleting the First element of the queue
		Dtraversal.push_back(mNode);


		for (int j = 0; j < mNode.edgeNodes.size(); j++){
			char ch = mNode.edgeNodes[j].data;
			if (!Dqueue.contains(ch) && !Dvisited.contains(ch)){
				Node n = graph.getNode(ch);
				Dvisited.push(n);
				Dqueue.push(n);
			}

		}
	}

	return Dtraversal;
}

vector<Node> traverseUCS(Graph graph){
	
	vector<Node> ucsTraversal;

	PriorityQueue priorityQueue;
	Queue expand;
	Queue explored;

	priorityQueue.push(graph.allNodes[0]);

	while (!priorityQueue.allNodes.empty()){
	
		Node mNode = priorityQueue.getFront();
		priorityQueue.pop();

		ucsTraversal.push_back(mNode);

		for (int j = 0; j < mNode.edgeNodes.size(); j++){
			char ch = mNode.edgeNodes[j].data;

			//Calculating the EdgeCosts 

			int thisCost= mNode.getCost()+mNode.edgeNodes[j].getCost();

			if (!priorityQueue.contains(ch) && !explored.contains(ch)){
				Node n = graph.getNode(ch);
				n.setCost(thisCost);
				explored.push(n);
				priorityQueue.push(n);
				expand.push(n);
			}
		}


	}

	return ucsTraversal;



}

int main(){
	cout << "BFS - DFS Demo" << endl;


	Graph graph;

	/*for (int i = 0; i < totalNodes; i++){
		cout << "Enter the node: " << endl;
		char in;
		cin >> in;

		Node currentNode(in);

		cout << "Enter the rest of the nodes that are connected to this node. Input 'x' to end the Input " << endl;

		while (in != 'x'){
			cin >> in;
			if (in == 'x')break;
			Node nextNode(in);
			currentNode.addEdgeNodes(nextNode);
		}

		graph.push_back(currentNode);

	}*/


	char nodes[8] = { 'A', 'P', 'W', 'R', 'U', 'M', 'L', 'R' };


	graph = inputGraphUCS(graph);
	
	outputGraph(graph);

	vector<Node> traversal;

	traversal = traverseBFS(graph);



	cout << "Outputting the Traversal Vector" << endl;

	for (int i = 0; i < traversal.size(); i++){
		cout << traversal[i].data << " ";
	}


	cout << endl;

	vector<Node> Dtraversal;

	Dtraversal = traverseDFS(graph);

	

	cout << "Outputting the Traversal Vector" << endl;

	for (int i = 0; i < Dtraversal.size(); i++){
		cout << Dtraversal[i].data << " ";
	}

	cout << endl;

	cout << "Uniform Cost Search Traversal Analysing ..... " << endl;

	vector<Node> ucsTraversal;

	ucsTraversal = traverseUCS(graph);

	for (int i = 0; i < ucsTraversal.size(); i++){
		cout << ucsTraversal[i].data << " ";
	}

	cout << endl;


	int consoleLast;
	cin >> consoleLast;
}