bool adj[9][9];     // adjacency matrix
int visit[9];       // �O��DFS�M���L���I
int order[9], n;    // �x�s�@�ӦX�z���ƦC����
 
bool cycle;         // �O��DFS���L�{���O�_��������
 
void DFS(int s)
{
    // back edge�A�����C
    if (visit[s] == 1) {cycle = true; return;}
    // forward edge�Bcross edge�C
    if (visit[s] == 2) return;
 
    visit[s] = 1;
    for (int t=0; t<9; ++t)
        if (adj[s][t])
            DFS(t);
    visit[s] = 2;
 
    order[n--] = s;     // �O���X�z���ƦC����
}
 
void topological_ordering()
{
    // ��l��
    for (int i=0; i<9; i++) visit[i] = 0;
    cycle = false;
    n = 9-1;
 
    // �i��DFS
    for (int s=0; s<9; ++s)
        if (!v[s])
            DFS(s);
 
    // ��X���G
    if (cycle)
        cout << "�ϤW����";
    else
        // �L�X�@�ӦX�z���ƦC����
        for (int i=0; i<9; ++i)
            cout << order[i];
}
