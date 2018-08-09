int main()
{
    int x,y;


	while (cin>>n && n)
	{
		cin>>m ;
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
	
			/*for(int i = 1; i <= n; i ++)
			{
				cout<<id[i]<<" " ;
			}
			cout<<endl;
			*/
	
			/*********************************************求初度为0****/
			/*for (int i = 1; i <= n; ++i) 
			{
				cout<<id[i]<<" " ;
			}
			cout<<endl;
			*/

			memset(boo, false, sizeof (boo));  
			int k;  
			for (int i = 1; i <= n; ++i)  
				for (k = start[i]; k != -1; k = edge[k].next)  
					if (id[i] != id[edge[k].point])  
						boo[id[i]] = true;  
			int p;  
			int cnt(0);  
			for (int i = 1,c = 0; i <= n; ++i) {  
				if (!boo[id[i]]) {  
					if(c == 0)
					{
						cout<<i ;
						c = 1 ;
					}else
					{
						cout<<" "<<i ;	
					}
					
				}  
			}  
			cout<<endl;
			

			/**********************************************************/


	}

	return 0;

}
