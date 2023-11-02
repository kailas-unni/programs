import openai

def get_response(prompt):
    openai.api_key = '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'

    response = openai.Completion.create(
        model = "text-davinci-003",
        prompt=prompt,
        temperature = 0,
        max_tokens = 1500,
        top_p = 1,
        frequency_penalty = 0,
        presence_penalty = 0,
        stop=["#",";"]
    )

    print(response['choices'][0]['text'])

get_response("Hi how are you")