import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.Vector;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        Vector<Integer>[] graph = new Vector[(N + 1) * 2];
        for (int i = 1; i <= N; ++i) {
            graph[i] = new Vector<>();
        }
        for (int i = 1; i < N; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");

            int vertex1 = Integer.parseInt(st.nextToken());
            int vertex2 = Integer.parseInt(st.nextToken());

            graph[vertex1].add(vertex2);
            graph[vertex2].add(vertex1);
        }

        int[] visited = new int[N + 1];

        bfs(graph, visited, 1);

        for (int i = 2; i <= N; ++i) {
            bw.write(visited[i] + "\n");
        }

        br.close();
        bw.flush();
        bw.close();
    }

    private static void bfs(Vector<Integer>[] graph, int[] visited, int startVertex) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(startVertex);

        while (queue.isEmpty() == false) {
            int currentVertex = queue.poll();

            for (int i : graph[currentVertex]) {
                if (visited[i] != 0) {
                    continue;
                }

                visited[i] = currentVertex;
                queue.add(i);
            }
        }
    }
}
