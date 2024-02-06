#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
template <typename k, typename v>
struct node
{
	node <k, v>*left;
	node <k, v>*right;
	node <k, v>*parent;
	k data; // roll number 
	v value;

	
	node(k v1,v v2)
	{
		parent=NULL;
		left=NULL;
		right=NULL;
		data=v1;
		value=v2;
	}
};
struct Trunk
{
	Trunk* prev;
	string str;

	Trunk(Trunk* prev, string str)
	{
		this->prev = prev;
		this->str = str;
	}
};

template <typename k, typename v>
class specialBST
{
	private:
		node <k, v>*root;
	public:
		specialBST()
		{
			root=NULL;
		}
		
		
	void insert(k datax, v val)
	{
		node <k, v>* N= new node<k,v>(datax,val);
		N->left=NULL;
		N->right=NULL;
		N->parent=NULL;
		bool flag=insertion(root,N);
		if(flag)
		cout<<endl<<" VALUE INSERTED "<<endl;
		else
		cout<<endl<<" VALUE NOT INSERTED" <<endl;
		
	}	
	
 	bool insertion(node <k, v>* &root, node<k, v>* N )
	{
		node <k, v>*temp =root;
		node <k, v>*y= NULL;	
		while( temp!=NULL)
		{
			y=temp;
			if(N->data==temp->data)
			{
				cout<<endl<<"		VALUE ALREADY EXISTS"<<endl;
				return false;
			}
			else if(N->data<temp->data)
			{
				temp=temp->left;
			}
			else 
			{
				temp=temp->right;
			}
		}
		N->parent=y;
		if(y==NULL)
		{
			root=N;
		}
		else if(N->data<y->data)
		{
			y->left=N;
		}
		else
		{
			y->right=N;
		}
		root=splay(root,N->data);
		return true;
		
	}

		node<k, v>* rightrotation(node <k, v>*root)
		{
		node <k, v>*temp=root;
		node <k, v>*temp_parent=root->parent;
		node <k, v>*primary =temp->left;
		node <k, v>*newtemp=primary->right;
		primary->right=temp;
		temp->parent=primary;
		temp->left=newtemp;
		if(newtemp!=NULL)
		{
			newtemp->parent=temp;
		}
		
		primary->parent=temp_parent;
		if(primary->parent != NULL)
		{
			if(primary->parent->left==temp)
			{
				primary->parent->left=primary;
			}
			else
			{
				primary->parent->right=primary;
			}
		}
		root=primary;
		return root;
		}
		
		node <k, v>* leftrotation(node <k, v>*root)
		{
		node <k, v>*temp=root;
		node <k, v>*temp_parent=root->parent;
		node <k, v>*primary =temp->right;
		node <k, v>*newtemp=primary->left;
		primary->left=temp;
		temp->parent=primary;
		temp->right=newtemp;
		if(newtemp!=NULL)
		{
			newtemp->parent=temp;
		}
		
		primary->parent=temp_parent;
		if(primary->parent != NULL)
		{
			if(primary->parent->left==temp)
			{
				primary->parent->left=primary;
			}
			else
			{
				primary->parent->right=primary;
			}
		}
		root=primary;
		return root;
		}
		
		
	node<k, v>* splay(node<k, v>* root, k key)
	{
		if (root == NULL || root->data == key)
			return root;
			
		if (root->data > key)
		{
				if (root->left == NULL) 
				return root;
				if (root->left->data > key)
				{
				root->left->left = splay(root->left->left, key);
				root = rightrotation(root);
				}
				else if (root->left->data < key) 
				{
				root->left->right = splay(root->left->right, key);
					if (root->left->right != NULL)
						root->left = leftrotation(root->left);
				}

			if(root->left == NULL)
			{
			return root;
			}
			else
			{
			 root=rightrotation(root);
			 return root;	
			}
		}
		else 
		{
			if (root->right == NULL)
				return root;
			if (root->right->data > key)
			{
				root->right->left = splay(root->right->left, key);
				if (root->right->left != NULL)
				{
					root->right = rightrotation(root->right);
				}
			}
			else if (root->right->data < key)
			{
				root->right->right = splay(root->right->right, key);
				root = leftrotation(root);
			}

			if(root->right == NULL)
			{
				return root;
			}
			else
			{
				root=leftrotation(root);
				return root;	
			}
			 
		}
	}


		
	    void inorder(node <k, v>*root)
		{	
		if(root==NULL)
		{
			return;
		}
		inorder(root->left);
		cout<<root->data<<" " <<endl;
		cout<<root->value<<endl<<endl;
		inorder(root->right);
		}
		
		
		
		void printinorder()
		{
		inorder(root);	
		}
		
		
		void preorder(node <k, v>*root)
		{	
		if(root==NULL)
		{
			return;
		}
		cout<<root->data<<" "<<endl;
		cout<<root->value<<endl;
		preorder(root->left);
		preorder(root->right);
		}
		
		
		
		void printpreorder()
		{
		preorder(root);	
		}
		
		
		void postorder(node <k, v>*root)
		{	
		if(root==NULL)
		{
			return;
		}	
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
		}
		
		
		
		void printpostorder()
		{
		postorder(root);	
		}
		

//	

		void destructorx(node <k, v>*root)
		{
		if (!root==NULL)
			{
				destructorx(root->left);
				destructorx(root->right);
				delete root;
			}
		}
		
		

		void srch(k key)
		{
	
			root=splay(root,key);
			
		}
				
		
		
	void deletion(int d)
	{
		bool flag=false;
		Delete(root,d,flag);
		if(flag)
		cout<<endl<<"value deleted"<<endl;
		else
		cout<<endl<<"NOT DELETED"<<endl;	
	}	
	node<k, v>* Delete(node<k, v>* root, k x ,bool &flag ) 
	{
	
    if (root == NULL) {
        cout << "Node not found ";
        flag =false;
        return NULL;
    }
    if (root -> data > x) {
        root -> left = Delete(root -> left, x,flag);
    }
    else if (root -> data < x){
        root -> right = Delete(root -> right , x,flag);
    }
    else {
        if (root -> left == NULL) {
            node <k, v>*temp = root -> right;
            free(root);
            flag=true;
            return temp;
    	}
        else if (root -> right == NULL) {
            node <k, v>*temp = root -> left;
            free(root);
            flag=true;
            return temp;
        }
        else {
            node <k, v>*temp = root -> right;
            while (temp -> left != NULL) 
            {
			temp = temp -> left;
			}
            root -> data = temp -> data;
            root -> right = Delete(root -> right, temp -> data,flag); 
        }
    }
    return root;
	}
			
			
		int getheight(node<k, v>* root) 
		{
		    if (root == NULL)
		        return 0;
		    else {
		        int lheight = getheight(root->left);
		        int rheight = getheight(root->right);
		        if (lheight > rheight) {
		            return(lheight + 1);
		        }
		        else {
		          return(rheight + 1);
		        }
		     	}
		}	
			
		void currentLevel(node<k, v>* root, int level)
		 {
		   if (root == NULL)
		        return;
			    if (level == 1)
		        cout << root->data << " ";
			    else if (level > 1) {
		        currentLevel(root->left, level-1);
		        currentLevel(root->right, level-1);
			    }
			}
		 
		void levelorderprint(node <k, v>* root) {
		    int h = getheight(root);
		    for (int i = 1; i <= h; i++)
		     currentLevel(root, i);
		}
		
		void levelorderprinting()
		{
			levelorderprint(root);
		}
		
				
		~specialBST()
		{
			cout<<endl<<endl<<"destructor called"<<endl;
			destructorx(root);
		}			
};
class student
{
	string firstname;
	string lastname;
	int batch;
	string department;
	float cgpa;	
	public:
	student()
	{
		firstname = " ";
		lastname = " ";
		batch = 0 ;
		department = " ";
		cgpa= 0.0 ;
	}
	void insertdata()
	{
		cout<<"enter first name "<<endl;
		cin>>firstname;
		cout<<"enter last name "<<endl;
		cin>>lastname;
		cout<<"enter batch"<<endl;
		cin>>batch;
		while((batch>2022 )||(batch<2016))
		{
			cout<<"invalid session enter again"<<endl;
			cin>>batch;
		}
		cout<<"enter name of department "<<endl;
		cin>>department;
		cout<<"enter the cgpa "<<endl;
		cin>>cgpa;
		while((cgpa>4.0 )||(cgpa<1.0))
		{
			cout<<" invalid gpa enter again"<<endl;
			cin>>cgpa;
		}
		
	}
	friend ostream& operator << (ostream& out, student obj)
	{
	out<<obj.firstname<<endl;
	out<<obj.lastname<<endl;
	out<<obj.batch<<endl;
	out<<obj.department<<endl;
	out<<obj.cgpa<<endl;
	return out;
	}
	
};

class studentslist
{
	specialBST <int,student> obj;
	student obj1;
public:
	void insert(int roll)
	{	
		obj1.insertdata();
		obj.insert(roll,obj1);
	}
	
	void deletestudent(int roll)
	{
		obj.deletion(roll);
	}
	void print()
	{
			obj.printinorder();
	}
	void preprint()
	{
		obj.printpreorder();
	}
	void update(int roll,int newroll )
	{
		obj.deletion(roll);
		obj1.insertdata();
		obj.insert(newroll,obj1);
	}
	
	void search(int roll)
	{
		obj.srch(roll);
	}
};
int main()
{
	studentslist onj;
	int rollnumber;
	int newroll;
	char decision='y';
	while(decision!='n')
	{
		cout<<"enter what you want to do "<<endl;
		cout<<"I for insertion"<<endl;
		cout<<"D for deletion "<<endl;
		cout<<"S for searching by roll number"<<endl;
		cout<<"U for update by roll number"<<endl;
		cout<<"R for printing in preorder"<<endl;
		cout<<"P for printing them in order "<<endl;
		cout<<"X to see the normal working with integers"<<endl;
		cout<<"n for exit"<<endl;
		cin>>decision;
		if(decision=='I')
		{
			cout<<"enter roll number "<<endl;
			cin>>rollnumber;
			while(rollnumber<=0)
			{
				cout<<"wrong input enter again";
				cin>>rollnumber;
			}
			onj.insert(rollnumber);
			system("pause");
			system("cls");
		}
		else if(decision=='D')
		{
			cout<<"enter roll number "<<endl;
			cin>>rollnumber;
			while(rollnumber<=0)
			{
				cout<<"wrong input enter again";
				cin>>rollnumber;
			}
			onj.deletestudent(rollnumber);
			system("pause");
			system("cls");
		}
		else if(decision=='S')
		{
			cout<<"enter roll number "<<endl;
			cin>>rollnumber;
			while(rollnumber<=0)
			{
				cout<<"wrong input enter again";
				cin>>rollnumber;
			}
			onj.search(rollnumber);
			system("pause");
			system("cls");
		}
		else if(decision=='U')
		{
			cout<<"enter roll number "<<endl;
			cin>>rollnumber;
			while(rollnumber<=0)
			{
				cout<<"wrong input enter again";
				cin>>rollnumber;
			}
			cout<<"enter new roll number "<<endl;
			cin>>newroll;
			while(rollnumber<=0)
			{
				cout<<"wrong input enter again";
				cin>>newroll;
			}
			onj.update(rollnumber,newroll);
			system("pause");
			system("cls");
		}
		else if(decision=='P')
		{
			onj.print();
			system("pause");
			system("cls");
		}
		else if(decision=='R')
		{
			onj.preprint();
			system("pause");
			system("cls");
		}
		else if(decision=='X')
		{
			specialBST <int,int> object;
			object.insert(10,1);
			object.insert(4,2);
			object.insert(-1,3);
			object.insert(14,4);
			object.insert(15,5);
			object.insert(19,6);
			object.insert(7,7);
			object.insert(89,8);
			system("cls");
			cout<<"CALLING PRE ORDER PRINT TO VERIFY THAT LAST INSERTED NODE IS ROOT"<<endl;
			object.printpreorder();
			system("pause");
			system("cls");
			cout<<"CHECKING THE SEARCH FUNCTION TO SEE IF INDEED THE LAST ACCESED NODE IS ROOT"<<endl;
			cout<<"NOTICE THAT I didnt insert 12 in inserting so I will first search 6 to see what happnes"<<endl;
			object.srch(12);
			object.printpreorder();
			system("pause");
			system("cls");
			cout<<"NOW WHAT IF WE SEARCH 19, AN ELEMENT THAT IS PRESENT ??"<<endl;
			object.srch(19);
			object.printpreorder();
			system("pause");
			system("cls");
			cout<<" NOW TO VIEW LEVEL ORDER PRINTING "<<endl;
			object.levelorderprinting();
			system("pause");
			system("cls");
		}
		else if(decision!='n')
		{
			cout<<"wrong choice enter again"<<endl;
			cin>>decision;
		}
	}
	
}
