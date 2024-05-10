class CustomerServiceChatbot:
    def __init__(self):
        # Initialize context with default values
        self.context = {
            "camera": {"size": "36 MP", "price": "$500"},
            "screen": {"size": "6.5 inches", "price": "$200"},
            "sim": {"size": "Nano-SIM", "price": "$20"},
            "ram": {"size": "8 GB", "price": "$100"},
            "memory": {"size": "128 GB", "price": "$50"},
            "battery": {"size": "4000 mAh", "price": "$80"},
            "current_context": {"context": "None"}  # Initialize current context to None
        }

    def handle_user_input(self, user_input):
        # Check if user input contains a keyword from context
        for keyword, info in self.context.items():
            if keyword in user_input:
                # Update current context
                self.context["current_context"] = info

                # Provide response based on context
                print("Chatbot:", end=" ")
                if user_input == keyword:
                    print(f"Size of {keyword} is {info['size']}.")
                    print(f"Price of {keyword} is {info['price']}.")
                else:
                    if "size" in user_input:
                        print(f"Size of {keyword} is {info['size']}.")
                    if "price" in user_input:
                        print(f"Price of {keyword} is {info['price']}.")
                    if "size" not in user_input and "price" not in user_input:
                        print("I'm sorry, I didn't understand your query. Could you please rephrase?")
                return

        # If no context matches, use previously stored context
        if self.context["current_context"]["context"] != "None":
            print("Chatbot:", end=" ")
            if "size" in user_input:
                print(f"Size of {self.context['current_context']['context']} is "
                      f"{self.context['current_context']['size']}.")
            elif "price" in user_input:
                print(f"Price of {self.context['current_context']['context']} is "
                      f"{self.context['current_context']['price']}.")
            else:
                print("I'm sorry, I didn't understand your query. Could you please rephrase?")
        else:
            print("Chatbot: I'm sorry, I didn't understand your query. Could you please provide more context?")


if __name__ == "__main__":
    chatbot = CustomerServiceChatbot()

    print("Welcome to Customer Service Chatbot")
    print("You can start chatting. Type 'bye' to exit.")

    while True:
        user_input = input("User: ")

        if user_input == "bye":
            print("Chatbot: Goodbye! Have a great day!")
            break

        chatbot.handle_user_input(user_input)
