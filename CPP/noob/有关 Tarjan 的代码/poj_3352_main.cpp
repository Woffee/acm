int main()
{
    int x,y;
	cin>>n>>m;
	{
		
		  init();
		  for(int i = 0; i < m ; i ++)
		  {
			  scanf("%d%d",&x,&y);
			  if(!map[x][y])
			  {
				  insert(x,y);
				  insert(y,x);
				  
				  map[x][y] = true ;
				  map[y][x] = true ;
			  }
		  }

		
		

		
				tarjan(1,1);//那么就搜它  

			int k;  
			for (int i = 1; i <= n; ++i)  
				for (k = start[i]; k != -1; k = edge[k].next)  
					if (id_un[i] != id_un[edge[k].point])  
					{
						degree[id_un[i]] ++ ;
					}
			int p;  
			int cnt = 0;  
			for (int i = 0; i <= n; ++i)
			{  
				if (degree[i] == 1) {  
					++cnt;  					
				}  
			}  
	
			cout<<(cnt + 1)/2<<endl;

	}

	return 0;

}
