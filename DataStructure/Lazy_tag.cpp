void modify(type value, int l, int r, int L, int R, vertex v){
    if(l == L && r == R){
        ���i�Цbv�W;
        return;
    }
    int M = (L + R) / 2;
    if(r <= M) modify(value, l, r, L, M, v�����l�`�I);
    else if(l > M) modify(value, l, r, M + 1, R, v���k�l�`�I);
    else{
        modify(value, l, M, L, M, v�����l�`�I);
        modify(value, M + 1, r, M + 1, R, v���k�l�`�I);
    }
    �Ψ�Ӥl�`�I�����ק�sv������;
}
