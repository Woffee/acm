int main()
{
    int x,y;


	while (cin>>n>>m && n + m != 0)
	{
		
		  init();
		  while(m --)
		  {
			  scanf("%d%d",&x,&y);
			  insert(x,y);
			  SPFNumber[x] = 0;
			  SPFNumber[y] = 0;
		  }

		bridge = 0;
		scc = 0 ;

		for(int i = 1; i <= n; i ++)  
			if(!dfn[i])//没有经过tarjan搜索过  
			{
				tarjan(i,0);//那么就搜它  
				SPFNumber[i] -- ;
			}
	
			if(scc == 1)
			{
				cout<<"Yes"<<endl;
			}else
			{
				cout<<"No"<<endl;
			}
	}

	return 0;

}
