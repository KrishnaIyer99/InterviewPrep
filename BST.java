public class BST{
	class Node{
        	int key;
        	Node left, right;
        	public Node(int data){
       	        	key = data;
                	left = right = null;
        	}
	}

	Node root;
	public BST(int data){
		root = new Node(data);
	}
	public BST(){
		root = null;
	}
	Node insertNode(Node root, int data){
		if(root == null){
			root = new Node(data);
			return root;
		}
		Node temp = root;
		while(true){
			if(temp.key < data){
				if(temp.right == null){
					temp.right = new Node(data);
					return root;
				}
				else{
					temp = temp.right;
				}
			}
			else{
				if(temp.left == null){
					temp.left = new Node(data);
					return root;
				}
				else{
					temp = temp.left;
				}
			}
		}
	}
	void inOrder(Node root){
		if(root != null){
			inOrder(root.left);
	                System.out.println(root.key);
        	        inOrder(root.right);

		}
	}
	public static void main(String[] args){
		BST tree = new BST();
		tree.root = tree.insertNode(tree.root, 50);
		tree.root = tree.insertNode(tree.root, 30);
		tree.root = tree.insertNode(tree.root, 20);
		tree.root = tree.insertNode(tree.root, 40);
		tree.root = tree.insertNode(tree.root, 70);
		tree.root = tree.insertNode(tree.root, 60);
		tree.root = tree.insertNode(tree.root, 80);
		//System.out.println(tree.root.left.key);
		tree.inOrder(tree.root);
	}
}
