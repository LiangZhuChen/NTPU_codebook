struct node{
	int val;
	node *l,*r;
	node(int v):val(v),l(0),r(0){}
	void pull(){val=min(l?>val,r?>val);}
}; //�� �� �� �P �� �X �� �� �k �i �H �� �g �o ��
int arr[N];//�� �� �C
node* build(int l,int r,node *p){
	if(l==r) return new node(arr[l]);
	int m=(l+r)/2;
	p=new node(0);//�o �� �u �O �H �K �� �� �@ �� �L �� �� �n �� ��
	p?>l=build(l,m,p?>l),p?>r=build(m+1,r,p?>r);
	p?>pull();
}
int query(int ql,int qr,int l,int r,node *p){//�d ��[ql,qr]�� �� �p ��
	if(ql<=l&&r<=qr) return p?>val;
	int m=(l+r)/2;
	if(qr<=m) return query(ql,qr,l,m,p?>l);
	if(ql>m) return query(ql,qr,m+1,r,p?>r);
	return min(query(ql,qr,l,m,p?>l),query(ql,qr,m+1,r,p?>r));
}
void modify(int x,int l,int r,node *p,int v){//�� �� �mx�� ��v
	if(l==r)
	return p?>val=v,void();
	int m=(l+r)/2;
	if(x<=m) modify(x,l,m,p?>l,v);
	else modify(x,m+1,r,p?>r,v);
	p?>pull();//�O �� �O �� �s �X �� �� ��
}
