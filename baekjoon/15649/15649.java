import java.io.*;
import java.util.StringTokenizer;
import java.util.Vector;

class Dfs {
    private int N, M;
    private Vector<Integer> result;
    private Vector<Boolean> visited;
    private BufferedReader br;
    private BufferedWriter bw;

    private void dfs(int currentIndex, int maxIndex, int maxNumber) throws IOException {
        if (currentIndex == maxIndex) {
            for (Integer i : this.result) {
                this.bw.write(i + " ");
            }
            this.bw.write("\n");
        }

        for (int i = 1; i <= maxNumber; ++i) {
            if (this.visited.get(i)) {
                continue;
            }

            this.visited.set(i, true);
            this.result.add(currentIndex, i);
            this.dfs(currentIndex + 1, maxIndex, maxNumber);
            this.visited.set(i, false);
            this.result.remove(currentIndex);
        }
    }

    public void run() throws IOException {
        this.br = new BufferedReader(new InputStreamReader(System.in));
        this.bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(this.br.readLine(), " ");

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        this.br.close();

        this.visited = new Vector<>();
        this.result = new Vector<>();

        for (int i = 0; i <= N; ++i) {
            this.visited.add(i, false);
        }

        this.dfs(0, M, N);

        this.bw.flush();
        this.bw.close();
    }
}

class Main {
    public static void main(String[] args) throws IOException {
        new Dfs().run();
    }
}
