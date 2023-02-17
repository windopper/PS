
                    if ( weight[b] == 0 && weight[a] != 0 ) {
                        weight[b] = weight[a] + w;
                    }
                    else if ( weight[b] != 0 && weight[a] == 0) {
                        weight[a] = weight[b] - w;
                    }
                    else if ( weight[b] == 0 && weight[a] == 0 ) {
                        weight[b] = w;
                    }