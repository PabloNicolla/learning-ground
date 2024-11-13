fn arrayManipulation(n: i32, queries: &[Vec<i32>]) -> i64 {
    let mut arr: Vec<i64> = vec![0; n as usize + 1]; // Use n+1 to handle range manipulation easily

    for q in queries {
        let start = (q[0] - 1) as usize; 
        let end = q[1] as usize; 
        let value = q[2] as i64;

        arr[start] += value;
        if end < arr.len() {
            arr[end] -= value;
        }
    }

    let mut max_value = 0;
    let mut current_value = 0;

    for &val in arr.iter() {
        current_value += val;
        max_value = max_value.max(current_value);
    }

    max_value
}
