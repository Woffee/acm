int main()
{
	int x,y;
	int m ,n;

	while (1)
	{
		m = 1000000 ;
		n = 0 ;
		  test++;
		  deep = 0;
		  init();
		  scanf("%d",&x);
		  if (x == 0)
			  break;

		  while (x != 0)
		  {
				scanf("%d",&y);
				if(m > x)
				{
					m = x ;
				}
				if(m > y)
				{
					m = y ;
				}
				if(n < x)
				{
					n = x ;
				}
				if(n < y)
				{
					n = y ;
				}
		  
				insert(x,y);
				insert(y,x);
				SPFNumber[x] = 0;
				SPFNumber[y] = 0;
				scanf("%d",&x);
		  }
		  bridge = 0;
				  //找到第一个存在的节点作为搜索树的跟节点 

		  //x = 1;

		  //while (SPFNumber[x] == -1) x++;
		x = m ;
		  tarjan(m,0);
		  SPFNumber[m] -- ;


			
		  int tip = 0;
			
		  printf("Network #%d\n",test);
		  for(int i = m ; i <= n; i ++)
		  {
			  if (SPFNumber[i] > 0) 
			  {
				 printf("  SPF node %d leaves %d subnets\n",i,SPFNumber[i] + 1);
				 tip = 1;
			  }

		  }
		  
		  if (tip == 0)
			  printf("  No SPF nodes\n");
		  printf("\n");

	}

	return 0;

}
