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
			if(!dfn[i])//û�о���tarjan������  
			{
				tarjan(i,0);//��ô������  
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
