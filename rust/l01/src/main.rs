// Basic Guessing Game
use std::{cmp::Ordering, io};
use rand::Rng;

fn main() {
    println!("Enter a number 1 - 10 inclusive");

    loop {
        let random_number = rand::thread_rng().gen_range(1..10);
        let mut guessed_number = String::new();
        io::stdin().read_line(&mut guessed_number).expect("Error reading input");

        let guessed_number: u32 =
            match guessed_number.trim().parse() {
                Ok(num) => num,
                Err(_) => {
                    println!("Error parsing str to u32");
                    continue;
                    }
                };

        println!("You guessed {}", guessed_number);
        println!("Random Value is {random_number}");
        /*Using binded if expressions */
        /*
       let message = if random_number < guessed_number {
           "Guess too high"
       } else if random_number > guessed_number {
           "Guess too low"
       }else{
          "Correct Guess"
       };
       */

       // match with comparison
       match guessed_number.cmp(&random_number) {
          Ordering::Equal => {println!("Correct Guess"); break;},
          Ordering::Greater => println!("Guess too high"),
          Ordering::Less =>  println!("Guess too low")
       };
    }
}
