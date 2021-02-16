class KnightTour {
    //

    constructor() {
        //

        this.N = 8;
        this.aa = Array.from({ length: this.N }, () => new Array(this.N));

        this.xMoves = [2, 1, -1, -2, -2, -1, 1, 2];
        this.yMoves = [1, 2, 2, 1, -1, -2, -2, -1];


    }

    isSafe(x, y) {
        return (
                   x >= 0 &&
                   x < this.N &&
                   y >= 0 &&
                   y < this.N &&
                   this.aa[x][y] == -1
               );
    }

    solveKT() {

        for (let x = 0; x < this.N; x++) {
            for (let y = 0; y < this.N; y++) {
                this.aa[x][y] = -1;
            }
        }

        this.aa[0][0] = 0;

        if (this.solveKTUtil(0, 0, 1)) {
            this.printSolution();
        } else {
            console.log("Solution does not exist");
        }
    }

    solveKTUtil(x, y, movei) {
        if (movei == this.N * this.N) return true;

        for (let k = 0; k < this.N; k++) {

            let next_x = x + this.xMoves[k];
            let next_y = y + this.yMoves[k];

            if (this.isSafe(next_x, next_y)) {

                this.aa[next_x][next_y] = movei;


                if (this.solveKTUtil(next_x, next_y, movei + 1)) {
                    return true;
                } else {
                    this.aa[next_x][next_y] = -1;
                }
            }
        }

        return false;
    }

    printSolution() {
        let str = "";
        for (let x = 0; x < this.N; x++) {
            str = "";
            for (let y = 0; y < this.N; y++) str += this.aa[x][y] + " ";
            console.log(str);
        }
    }
}

let a = new KnightTour();
a.solveKT();