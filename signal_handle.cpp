#include <iostream>
#include <csignal>
#include <unistd.h> // For sleep function

// Signal handler function
void signalHandler(int signal) {
    if (signal == SIGINT) {
        std::cout << "Interrupt signal (SIGINT) received." << std::endl;
        // Perform any cleanup or exit tasks here
        exit(signal);
    }
}

int main() {
    // Register the signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, signalHandler);

    std::cout << "Program running... Press Ctrl+C to interrupt." << std::endl;

    while (true) {
        std::cout << "Sleeping..." << std::endl;
        sleep(1); // Sleep for 1 second
    }

    return 0;
}
