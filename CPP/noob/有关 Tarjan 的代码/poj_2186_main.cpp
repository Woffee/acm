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
	
			/*for(int i = 1; i <= n; i ++)
			{
				cout<<id[i]<<" " ;
			}
			cout<<endl;
			*/
	
			/*********************************************求初度为0****/

			memset(boo, false, sizeof (boo));  
			int k;  
			for (int i = 1; i <= n; ++i)  
				for (k = start[i]; k != -1; k = edge[k].next)  
					if (id[i] != id[edge[k].point])  
						boo[id[i]] = true;  
			int p;  
			int cnt(0);  
			for (int i = 1; i <= scc; ++i) {  
				if (!boo[i]) {  
					++cnt;  
					p = i;  
				}  
			}  
			if (cnt > 1)  
				printf("0\n");  
			else {  
				cnt = 0;  
				for (int i = 1; i <= n; ++i)  
					if (id[i] == p) ++cnt;  
				printf("%d\n", cnt);  
			}  

			/**********************************************************/


	}

	return 0;

}
