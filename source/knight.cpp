#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
	ifstream file;
	file.open(file_input, ios::in);
	file>>HP>>level>>remedy>>maidenkiss>>phoenixdown;
	rescue=-1;
	string s;
	string dong3;
	string fmg,fap,fmp;
	getline(file, s);
	getline(file, s);
	int kk = 0;
    int khoangtrang; 
    int sukien = 0;
    while(1)
    {
        khoangtrang = s.find(" ", kk);
        if (khoangtrang == -1)
        break;
        sukien ++;
        kk = khoangtrang + 2;
    }
    sukien++;
    //long long sk[sukien+1];
	long long* sk = new long long[sukien + 1];
    int j = 1;
    stringstream hhang2(s);
    for(; j <= sukien; j++)
    {
        hhang2 >> sk[j];
    }
   
    getline(file, fmg, ',');
    getline(file, fap, ',');
    getline(file, fmp);
	file.close();
	int MaxHP=HP;
	int r1,c1;
	int sothuoc=0;
	long long dms, n;//nam ma
		int ms[100];
	
		
    //sk
    	long long b, levelO,min, max, imin, imax, th=0,ech=0, levelt, damage, mtx, mti,lom,nto,s1,n1,fibott,fibot,fibos;
    	long long gapmerlin=0, gapap=0, ktngto=0, ln, nn,max2_3x, max2_3i,maxi2, mini2, max3,min3;
    	int vitri1, vitri2, vitri3, vitri4;
    	string mlin;
    	float baseDamage;
    	levelt=level;
    	for(int a=1;a<HP+1;a++)
    	{
    		if(HP%a==0) ktngto++;
		}
		for(int i=1; i<sukien+1; i++)
{
	b=i%10; 
	levelO =i>6?(b>5?b:5):b;
if(sk[i]==0)
    {   
    	rescue=1;
    	display( HP, level, remedy, maidenkiss, phoenixdown, rescue);
    	break;
	}
else if(sk[i]>0 && sk[i]<6) 
{
	if(level>levelO||MaxHP==999||ktngto==2)
	{
			if(level<10) level++;
	}
	else if(level<levelO)
	{
		if(sk[i]==1)
		baseDamage=1;
		else if(sk[i]==2)
		baseDamage=1.5;
		else if(sk[i]==3)
		baseDamage=4.5;
		else if(sk[i]==4)
		baseDamage=7.5;
		else if(sk[i]==5)
		baseDamage=9.5;
		damage=baseDamage*levelO*10;
		HP=HP-damage;
		if(HP<=0)
		{
			if(phoenixdown==0)
			{
				rescue=0;
				display( HP, level, remedy, maidenkiss, phoenixdown, rescue);
				break;
			}
			else
			{
				phoenixdown--;
				if(ech>0) level=levelt;
				th=0;
				ech=0;
				HP=MaxHP;
			}
		}
	
	}
	if(th>0) th++;
	if(ech>0) ech++;
}
else if(sk[i]==6)
	{
		if(ech>0 or th>0 )
		{
			if(th>0) th++;
			if(ech>0) ech++;
			if(i==sukien)	rescue=1;
			if(th==4)
			{
				th=0;
				HP=HP*5;
				if(HP>MaxHP)
				HP=MaxHP;
			}
			if(ech==4)
			{
				ech=0;
				level=levelt;
			}
			display( HP, level, remedy, maidenkiss, phoenixdown, rescue);
			continue;
		}
		if(level>levelO||MaxHP==999||ktngto==2)
		{
		if(level<9) level=level+2;
		else if(level<10) level=level+1;
		}
		else if(level<levelO&&remedy==0)
		{
			th=1;
			HP=HP/5;
			if(HP==0) HP=1;
		}
		else if(level<levelO&&remedy>0)
		remedy--;
		
	}
else if(sk[i]==7)
	{
		if(ech>0 or th>0 )
		{	if(th>0) th++;
			if(ech>0) ech++;
			if(i==sukien)	rescue=1;
			if(th==4)
			{
				th=0;
				HP=HP*5;
				if(HP>MaxHP)
				HP=MaxHP;
			}
			if(ech==4)
			{
				ech=0;
				level=levelt;
			}
			display( HP, level, remedy, maidenkiss, phoenixdown, rescue);
			continue;
		}
		if(level>levelO||MaxHP==999||ktngto==2)
		{
		if(level<9) level=level+2;
		else if(level<10) level=level+1;
		}
		else if(level<levelO&&maidenkiss==0)
		{
			ech=1;
			levelt=level;
			level=1;
		}
		else if(level<levelO&&maidenkiss>0)
		maidenkiss--;
	}
	else if(sk[i]==11)
	{
		n1=((level+phoenixdown)%5+1)*3;
		s1=0;
		for(int t=0;t<n1;t++)
		s1=s1+99-2*t;
		HP=HP+(s1%100);
		nto=0;
		while(nto!=2)  
		{	
			nto=0;
			HP++;
			for(int h=1;h<=HP;h++)
			{
				if(HP%h==0){
				nto++;
				}
			}
		}
		if(HP>MaxHP) HP=MaxHP;
		if(th>0) th++;
		if(ech>0) ech++;
		
	}
else if(sk[i]==12)
	{
		fibott=1, fibot=1;
	while(1)
	{
		if(HP==1)
		{
			break;
		}
		fibos=fibott+fibot;
		fibott=fibot;
		fibot=fibos;
		if(HP<=fibos)
		{
			HP=fibott;
			break;
		}
	}
	if(th>0) th++;
	if(ech>0) ech++;
	}
		else if(sk[i]==17)
	{
		if(phoenixdown<99)
		phoenixdown++;
		if(th>0) th++;
		if(ech>0) ech++;
	}
	else if(sk[i]>130)	
	{		ifstream file_mg;
		file_mg.open(fmg, ios::in);
		int n2;
		string dsomg;
		file_mg>>n2;
		getline(file_mg,dsomg);
		stringstream ss(dsomg);
		int namma[100];
		int namma3[100];
		for(int t=0;t<n2;t++)
		{
			getline(file_mg,dsomg, ',');
			stringstream ss(dsomg);
			ss>>namma[t];
		}
		file_mg.close();
		dms=0;
		n=1;
		for(; dms>=0;n++)
		{
			dms=sk[i]-13*pow(10,n);
		}
		n=n-2;
		dms=sk[i]-13*pow(10,n);
		for(int i=n-1;i>=0;i--)
		{
			ms[i]=dms%10;
			dms=dms/10;
		}
			for(int t=0;t<n2;t++)
				{
					if(namma[t]<0)
					namma3[t]=(-17*namma[t]+9)%257;
					else
					namma3[t]=(17*namma[t]+9)%257;
				}
				
		for(int i=0;i<n;i++)//su kien nam ma
		{
			if(ms[i]==1)// nam ma 1
			{
				max=namma[0], min=namma[0], imax=0, imin=0;
				for(int t=0;t<n2;t++)
				{
					if(namma[t]>=max)
					{
						max=namma[t];
						imax=t;
					}
					if(namma[t]<=min)
					{
						min=namma[t];
						imin=t;
					}
				}
				HP=HP-(imax+imin);
				if(HP<=0)
				{
					if(phoenixdown==0)
					{
						rescue=0;
						display( HP, level, remedy, maidenkiss, phoenixdown, rescue);
						break;
					}
					else
					{
						phoenixdown--;
						if(ech>0) level=levelt;
						th=0;
						ech=0;
						HP=MaxHP;
					}
				}
			} 
			else if(ms[i]==2)
			{
				lom=0;
				for(int t=1;t<n2-1;t++)
				{
					if((namma[t]<namma[t-1]&&namma[t]<namma[t+1]) or namma[t]==namma[t-1] or namma[t]==namma[t+1] )
					lom++;
				}
				if(lom>0)
				{
					mtx=-2;
					mti=-3;
				}
				else 
				{
					mtx=namma[0];
					for(int t=0;t<n2;t++)
					if(namma[t]>mtx) 
					{
						mtx=namma[t];
						mti=t;
					}
				}
				HP=HP-(mtx+mti);
				if(HP>MaxHP)
				HP=MaxHP;
				if(HP<=0)
				{
					if(phoenixdown==0)
					{
						rescue=0;
						display( HP, level, remedy, maidenkiss, phoenixdown, rescue);
						break;
					}
					else
					{
						phoenixdown--;
						if(ech>0) level=levelt;
						th=0;
						ech=0;
						HP=MaxHP;
					}
				}
			}
			else if(ms[i]==3)
			{
				maxi2=0, mini2=0;
				max3=namma3[0];
				min3=namma3[0];
				for(int t=0;t<n2;t++)
				{
					if(namma3[t]>max3)
					{
						max3=namma3[t];
						maxi2=t;
					}
					if(namma3[t]<min3)
					{
						min3=namma3[t];
						mini2=t;
					}
				}
				HP=HP-(maxi2+mini2);
				if(HP<=0)
				{
					if(phoenixdown==0)
					{
						rescue=0;
						display( HP, level, remedy, maidenkiss, phoenixdown, rescue);
						break;
					}
					else
					{
						phoenixdown--;
						if(ech>0) level=levelt;
						th=0;
						ech=0;
						HP=MaxHP;
					}
				}
			}
			else if(ms[i]==4)
			{
				if(namma3[0]==namma3[1]&&namma3[1]==namma3[2])
				{
					max2_3x=-5;
					max2_3i=-7;
				}
				else 
				{
					ln=namma3[0];
					nn=namma3[0];
					for(int t=0;t<3;t++)
					{
						if(namma3[t]>ln)
						ln=namma3[t];
						if(namma3[t]<nn)
						nn=namma3[t];
					}
					int kmin=0;
					for(int t=0; t<3; t++)
					{
						if(namma3[t]>nn&&namma3[t]<ln)
						{
							max2_3x=namma3[t];
							max2_3i=t;
							
						} 
						if(namma3[t]==nn)
							kmin++;
					}
					if(kmin==2)
					{
					max2_3x=-5;
					max2_3i=-7;
					}
					
				}
					HP=HP-(max2_3x+max2_3i);
					if(HP>MaxHP)
				HP=MaxHP;
				if(HP<=0)
				{
					if(phoenixdown==0)
					{
						rescue=0;
						display( HP, level, remedy, maidenkiss, phoenixdown, rescue);
						break;
					}
					else
					{
						phoenixdown--;
						if(ech>0) level=levelt;
						th=0;
						ech=0;
						HP=MaxHP;
					}
				}
			}
			
		}
		if(rescue==0) break;
		if(th>0) th++;
		if(ech>0) ech++;
	}//vung trong for sk lon
	else if(sk[i]==19)
	{
			ifstream file_ap;
	file_ap.open(fap, ios::in); 
	file_ap>>r1>>c1;
	int apmt[100][100];
	for(int a=0;a<r1;a++)
	{
		for(int b=0;b<c1;b++)
		{
			file_ap>>apmt[a][b];			
		}
	}
	file_ap.close();
		if(gapap==0)
		{
		for(int h=0; h<r1;h++)
		{
			sothuoc=0;
			for(int k=0;k<c1;k++)
			{
				if(apmt[h][k]==16)
				{
					if(remedy<99)
					remedy++;
					sothuoc++;
					if(sothuoc==3)
					break;
				}
					if(apmt[h][k]==17)
				{
					if(maidenkiss<99)
					maidenkiss++;
					sothuoc++;
					if(sothuoc==3)
					break;
				}
					if(apmt[h][k]==18)
				{
					if(phoenixdown<99)
					phoenixdown++;
					sothuoc++;
					if(sothuoc==3)
					break;
				}
			}	
		}
		if(th>0)
		{
			th=0;
			remedy--;
			HP=HP*5;
			if(HP>MaxHP)
			HP=MaxHP;
		}
			if(ech>0)
		{
			maidenkiss--;
			ech=0;
			level=levelt;
		}
	}
		gapap++;
		if(th>0) th++;
		if(ech>0) ech++;
	}
	else if(sk[i]==18)
	{
		if(gapmerlin==0)
		{
		int n9;
		ifstream file_mp;
		file_mp.open(fmp, ios::in);
		file_mp>>n9;
		getline(file_mp, mlin);
		for(int t=0;t<n9;t++)
		{	
			getline(file_mp, mlin);
			vitri1=mlin.find("Merlin");
			vitri2=mlin.find("merlin");
			if(vitri1!=-1||vitri2!=-1)
			{	
				HP=HP+3;
				continue;
			}
			vitri3=mlin.find("M");
			vitri4=mlin.find("m");
			if(vitri3!=-1||vitri4!=-1)
			{
				vitri3=mlin.find("E");
				vitri4=mlin.find("e");
				if(vitri3!=-1||vitri4!=-1)
				{
					vitri3=mlin.find("R");
					vitri4=mlin.find("r");
					if(vitri3!=-1||vitri4!=-1)
					{
						vitri3=mlin.find("L");
						vitri4=mlin.find("l");
						if(vitri3!=-1||vitri4!=-1)
						{
							vitri3=mlin.find("I");
							vitri4=mlin.find("i");
							if(vitri3!=-1||vitri4!=-1)
							{
								vitri3=mlin.find("N");
								vitri4=mlin.find("n");
								if(vitri3!=-1||vitri4!=-1)
								{
									HP=HP+2;
								} else continue;
							} else continue;
						} else continue;
					} else continue;
				} else continue;
			} else continue;
		} 
		file_mp.close();
		if(HP>MaxHP) HP=MaxHP;
		}
		gapmerlin++;
		if(th>0) th++;
		if(ech>0) ech++;
	}
	else if(sk[i]==15)
	{
		if(th>0)
		{
			th=0;
			HP=HP*5;
			if(HP>MaxHP)
			HP=MaxHP;
		}
		else if(remedy<99) remedy++;
		if(ech>0) ech++;
	}
	else if(sk[i]==16)
	{
		if(ech>0)
		{
			ech=0;
			level=levelt;
		}
		else if(maidenkiss<99)
		maidenkiss++;
		if(th>0) th++;
	}
	else if(sk[i]==17)
	{
		if(phoenixdown<99)
		phoenixdown++;
		if(th>0) th++;
		if(ech>0) ech++;
	}
		else if(sk[i]==99) 
	{
		if(MaxHP==999||(ktngto==2&&level>7)||level==10)
		level=10;
		else 
		{
			rescue=0;
			display( HP, level, remedy, maidenkiss, phoenixdown, rescue);
			break;
		}
	}
	if(i==sukien)	rescue=1;
	if(th==4)
	{
		th=0;
		HP=HP*5;
		if(HP>MaxHP)
		HP=MaxHP;
	}
	if(ech==4)
	{
		ech=0;
		level=levelt;
	}
	display( HP, level, remedy, maidenkiss, phoenixdown, rescue);
}
}
	
