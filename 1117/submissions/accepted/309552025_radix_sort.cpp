#include <bits/stdc++.h>
using namespace std;

struct point{
	int id;
	int x, y, z;
};

int main(){
	int n;
	scanf("%d", &n);
	vector<point> points(n), temp(n);
	for(int i = 0; i < n; i++){
		points[i].id = i;
		scanf("%d %d %d", &points[i].x, &points[i].y, &points[i].z);
	}

	vector<point> copy_points(points.begin(), points.end());
	vector<int> dup_x(n), dup_y(n), dup_z(n), dup_xy(n), dup_xz(n), dup_yz(n), dup_xyz(n);

	// sort by x
	{
		vector<int> cnt(n), prefix_sum(n);
		for(int i = 0; i < n; i++) cnt[copy_points[i].x]++;
		prefix_sum[0] = cnt[0];
		for(int i = 1; i < n; i++) prefix_sum[i] = prefix_sum[i-1] + cnt[i];
		for(int i = 0; i < n; i++){
			dup_x[copy_points[i].id] = cnt[copy_points[i].x] - 1;
			temp[--prefix_sum[copy_points[i].x]] = copy_points[i];
		}
		copy(temp.begin(), temp.end(), copy_points.begin());
	}

	// sorted by y after sorted by x
	{
		vector<int> cnt(n), prefix_sum(n);
		for(int i = 0; i < n; i++) cnt[copy_points[i].y]++;
		prefix_sum[0] = cnt[0];
		for(int i = 1; i < n; i++) prefix_sum[i] = prefix_sum[i-1] + cnt[i];
		for(int i = 0; i < n; i++){
			dup_y[copy_points[i].id] = cnt[copy_points[i].y] - 1;
			temp[--prefix_sum[copy_points[i].y]] = copy_points[i];
		}
		copy(temp.begin(), temp.end(), copy_points.begin());
		for(int i = 0; i < n; ){
			int st = i, ed = i + 1;
			while(ed < n && copy_points[st].x == copy_points[ed].x && copy_points[st].y == copy_points[ed].y) ed++;
			while(i < ed){
				dup_xy[copy_points[i].id] = ed - st - 1;
				i++;
			}
		}
	}

	// sorted by z after sorted by x and y
	{
		vector<int> cnt(n), prefix_sum(n);
		for(int i = 0; i < n; i++) cnt[copy_points[i].z]++;
		prefix_sum[0] = cnt[0];
		for(int i = 1; i < n; i++) prefix_sum[i] = prefix_sum[i-1] + cnt[i];
		for(int i = 0; i < n; i++){
			dup_z[copy_points[i].id] = cnt[copy_points[i].z] - 1;
			temp[--prefix_sum[copy_points[i].z]] = copy_points[i];
		}
		copy(temp.begin(), temp.end(), copy_points.begin());
		for(int i = 0; i < n; ){
			int st = i, ed = i + 1;
			while(ed < n && copy_points[st].x == copy_points[ed].x && copy_points[st].y == copy_points[ed].y
				  && copy_points[st].z == copy_points[ed].z) ed++;
			while(i < ed){
				dup_xyz[copy_points[i].id] = ed - st - 1;
				i++;
			}
		}
		for(int i = 0; i < n; ){
			int st = i, ed = i + 1;
			while(ed < n && copy_points[st].y == copy_points[ed].y && copy_points[st].z == copy_points[ed].z) ed++;
			while(i < ed){
				dup_yz[copy_points[i].id] = ed - st - 1;
				i++;
			}
		}
	}

	// sort by x after sorted by x, y and z
	{
		vector<int> cnt(n), prefix_sum(n);
		for(int i = 0; i < n; i++) cnt[copy_points[i].x]++;
		prefix_sum[0] = cnt[0];
		for(int i = 1; i < n; i++) prefix_sum[i] = prefix_sum[i-1] + cnt[i];
		for(int i = 0; i < n; i++) temp[--prefix_sum[copy_points[i].x]] = copy_points[i];
		copy(temp.begin(), temp.end(), copy_points.begin());
		for(int i = 0; i < n; ){
			int st = i, ed = i + 1;
			while(ed < n && copy_points[st].x == copy_points[ed].x && copy_points[st].z == copy_points[ed].z) ed++;
			while(i < ed){
				dup_xz[copy_points[i].id] = ed - st - 1;
				i++;
			}
		}
	}

	for(int i = 0; i < n; i++)
		printf("%d%c", (n - 1) - (dup_x[i] + dup_y[i] + dup_z[i] - (dup_xy[i] + dup_xz[i] + dup_yz[i]) + dup_xyz[i]), " \n"[i==n-1]);
}