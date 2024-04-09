// Basic Guessing Game
use std::{cmp::Ordering, io};
use rand::Rng;


fn guessing_game() {
    let mut how_many = String::new();
    println!("How many rand num do you want to guess");
    io::stdin().read_line(&mut how_many).expect("Error reading input");
    let num_guesses: u8 = how_many.trim().parse().expect("Error Parsing");

    let mut correct = Vec::new();

    for _ in 0..num_guesses  {
        correct.push(rand::thread_rng().gen_range(1..20))
    }

    println!("{correct:?}");

    let mut guesses_made = 0;

    println!("Guess from 1 - 20");
  while guesses_made < num_guesses  {
        // let random_number = rand::thread_rng().gen_range(1..10);
        let mut  guessed_number = String::new();
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

       match guessed_number.cmp(&correct[guesses_made as usize]) {
          Ordering::Equal => {
              println!("Correct Guess");
              guesses_made += 1;
              if guesses_made < num_guesses {
                  println!("Next Index")
              }
          },
          Ordering::Greater => println!("Guess too high"),
          Ordering::Less =>  println!("Guess too low")
       };
       }

       println!("Thanks for playing!");

       for item in correct {
           println!("{item}")
       }

}

fn main() {
    guessing_game()
}
