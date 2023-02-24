import java.util.*;
import java.io.*;

class Data implements Comparable<Data> {
    int node, weight;

    public Data(int node, int weight) {
        this.node = node;
        this.weight = weight;
    }

    @Override
    public int compareTo(Data d){
        return Integer.compare(this.weight, d.weight);
    }
}
public class Main {
    static ArrayList<Data>[] graph;
    static boolean[] visited;
    static int[] weight;

    public static void Dijkstra2(int n, int start) {
        boolean[] visited = new boolean[n+1];
        int[] weight = new int[n+1];
        final int INF = Integer.MAX_VALUE;
        
        Arrays.fill(weight, INF);

        weight[start] = 0;
        PriorityQueue<Data> pq = new PriorityQueue<>();
        pq.offer(new Data(start,0));

        while(!pq.isEmpty()) {
            Data curr = pq.peek();
            pq.remove();

            if(visited[curr.node]) continue;
            visited[curr.node] = true;

            for(int i=0; i<graph[curr.node].size();i++) {
                Data next = graph[curr.node].get(i);
                weight[next.node] = Math.min(weight[next.node], weight[curr.node]+next.weight);
                pq.offer(new Data(next.node,weight[next.node]));
            }
        }
        for(int i : weight) {
            if(i==INF) System.out.print(0 + " ");
            else System.out.print(i+" ");
        }
    }

    public static void main(String[] args) throws IOException {
        // 그래프 입력 받기
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        // 정점의 갯수, 간선의 갯수
        int n = Integer.parseInt(bf.readLine());
        int m = Integer.parseInt(bf.readLine());

        graph = new ArrayList[n+1];
        for(int i=0; i<=n; i++) graph[i] = new ArrayList<>();

        StringTokenizer st;
        for(int i=0; i<m; i++) {
            st = new StringTokenizer(bf.readLine());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            graph[v].add(new Data(w, weight));
        }
        int start = Integer.parseInt(bf.readLine());

        Dijkstra2(n, start);
    }
}
