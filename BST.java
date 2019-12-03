public class BST{
	class Node{//sub-class for node objects in BST
        	int key;
        	Node left, right; //left and right child
        	public Node(int data){//Node object constructor
       	        	key = data;
                	left = right = null;
        	}
	}

	Node root;//head of tree

	//constructors for BST object
	public BST(int data){
		root = new Node(data);
	}
	public BST(){
		root = null;
	}
	Node insertNode(Node root, int data){//insert function returns root of tree
		if(root == null){//base case (empty tree)
			root = new Node(data);
			return root;
		}
		Node temp = root;//create temporary object to traverse through tree
		while(true){
			if(temp.key < data){//traverse right sub-tree
				if(temp.right == null){// if right child does not exist
					temp.right = new Node(data);
					return root;
				}
				else{
					temp = temp.right;
				}
			}
			else{//traverse left subtree
				if(temp.left == null){//if left child does not exist
					temp.left = new Node(data);
					return root;
				}
				else{
					temp = temp.left;
				}
			}
		}
	}
	void inOrder(Node root){//inorder traversal of tree (recursively)
		if(root != null){
			inOrder(root.left);
			System.out.println(root.key);
			inOrder(root.right);

		}
	}
	int maxValue(){//get max value in tree
		Node temp = this.root;
		int val = 0;
		while(temp.right != null){//continue to traverse through right childs
			val = temp.right.key;
			temp = temp.right;
		}
		return val;
	}
	int minValue(){//get min value in tree
		Node temp = this.root;
		int val = 0;
		while(temp.left != null){//continue to traverse through left childs
			val = temp.left.key;
			temp = temp.left;
		}
		return val;
	}
	Node search(int key){//value of node as input, returns null if node not found
		Node temp = this.root;
		while(temp != null){//keep searching until leaf node is reached
			System.out.println(temp.key);
			if(temp.key == key){//check if node has been found
				System.out.println("Node found!");
				return temp;
			}
			else if(temp.key < key){//go to right child
				temp = temp.right;
			}
			else{
				temp = temp.left;//go to left child
			}
		}
		System.out.println("Node not found");
		return null;		
	}

	public static void main(String[] args){//driver program
		BST tree = new BST();
		tree.root = tree.insertNode(tree.root, 50);
		tree.root = tree.insertNode(tree.root, 30);
		tree.root = tree.insertNode(tree.root, 20);
		tree.root = tree.insertNode(tree.root, 40);
		tree.root = tree.insertNode(tree.root, 70);
		tree.root = tree.insertNode(tree.root, 60);
		tree.root = tree.insertNode(tree.root, 80);
		System.out.println(tree.minValue());
		//tree.inOrder(tree.root);
		tree.search(60);
		tree.search(25);
	}
}
