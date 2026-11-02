#ifndef HARMONIC_H
#define HARMONIC_H

static inline double harmonic_mean(const double *values, int count) {
    double sum = 0;
    for (int index = 0; index < count; index++) {
        sum += 1.0 / values[index];
    }
    return count / sum;
}

#define HARMONIC_MEAN(values, count) (harmonic_mean((values), (count)))

#endif
