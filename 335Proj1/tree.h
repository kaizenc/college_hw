class Tree{
	private:
		string spc_common;
		int tree_id;
		int tree_dbh;
		string status;
		string health;
		string address;
		string boroname;
		int zipcode;
		double latitude;
		double longitude;
		
	public:
		Tree(const string & treedata); 
		ostream& operator<< (ostream & os);
		string write();
}