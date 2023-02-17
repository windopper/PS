#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int sam = 1;
int tes = 0;
vector<vector<int>> vec;
vector<int> key(110000, 0);
vector<int> num(110000, 0);
int s1 = 0;
int s2 = 0;
int tn = 1;
int w = 0;
int w1 = 0;
int ss = 0;
char k;

int main()
{

    while (sam != 0)
    { // 둘다 값이 0 이면 나온다.

        cin >> sam >> tes; //  sam 받긴 하는데 어따 써야 할지 모르겠음 배열 할당에나 쓸까

        for (int i = 0; i < tes; i++)
        { // 테스트 케이스 만큼 진행

            cin >> k >> s1 >> s2;
            if (k == '!')
            { // !값을 입력받았을때
                cin >> w;
                if (key[s1] == 0)
                { // s1값이 없으면
                    if (key[s2] == 0)
                    { // s2값까지 없으면  새로 백터 생성
                        num[s1] = 0;
                        num[s2] = w;
                        vector<int> v2(1, 2); // 첫번째 값에 원소의 개수를 둘거임
                        v2.push_back(s1);
                        v2.push_back(s2);
                        vec.push_back(v2); // vec[0]에 저장됨   key[s1] = 1
                        key[s1] = tn;      // K값은 새로 백터가 만들어진 횟수
                        key[s2] = tn;
                        tn += 1;
                    }
                    else
                    { // s2값만있으면  s1을 흡수
                        num[s1] = num[s2] - w;
                        key[s1] = key[s2];
                        vec[key[s2] - 1].push_back(s1);
                        vec[key[s2] - 1][0] += 1;
                    }
                }
                else
                { // s1값이 있으면
                    if (key[s2] == 0)
                    { // s2값은 없으면 s2를 흡수
                        num[s2] = num[s1] + w;
                        key[s2] = key[s1];
                        vec[key[s1] - 1].push_back(s2);
                        vec[key[s1] - 1][0] += 1;
                    }
                    else if (key[s1] != key[s2])
                    { /// 둘다 값이 있고 같은 분류에 속해있지 않으면 사이즈가 큰쪽으로 병합
                        int s1k = key[s1] - 1;
                        int s2k = key[s2] - 1;
                        if (vec[s1k][0] >= vec[s2k][0])
                        {
                            w1 = w - num[s2] + num[s1];
                            for (int i = 1; i < vec[s2k][0] + 1; i++)
                            {
                                ss = vec[s2k][i];
                                num[ss] += w1;
                                vec[s1k].push_back(ss);
                                vec[s1k][0] += 1;
                                key[ss] = key[s1];
                            }
                            vector<int>().swap(vec[s2k]);
                        }
                        else
                        {
                            w1 = -w + num[s2] - num[s1];
                            for (int i = 1; i < vec[s1k][0] + 1; i++)
                            {
                                ss = vec[s1k][i];
                                num[ss] += w1;
                                vec[s2k].push_back(ss);
                                vec[s2k][0] += 1;
                                key[ss] = key[s2];
                            }
                            vector<int>().swap(vec[s2k]);
                        }
                    }
                }
            }
            else
            { // ?값을 입력받았으면
                if (key[s1] == key[s2])
                {
                    cout << num[s2] - num[s1];
                }
                else
                {
                    cout << "UNKNOWN";
                }
            }
        }
        vector<vector<int>> vecem;
        vecem.swap(vec);
        fill(key.begin(), key.begin() + sam + 1, 0);
        fill(num.begin(), key.begin() + sam + 1, 0);
        tn = 1;
    }
}