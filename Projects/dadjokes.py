import aiohttp
import asyncio

headers = {"Accept": "application/json"}


async def main(amount: int = 1):
    counter = 1
    async with aiohttp.ClientSession(headers=headers) as session:
        with open("./jokes.txt", 'w', encoding="utf-8") as file:
            for _ in range(amount):
                async with session.get("https://icanhazdadjoke.com/") as result:
                    jsoned = await result.json()
                joke = "{}. {}".format(counter, jsoned['joke'])
                file.write(joke + '\n')
                print(joke)
                counter += 1
    return


if __name__ == "__main__":
    while True:
        try:
            amount = int(input("How many dad jokes would you like me to fetch: "))
            break
        except ValueError:
            print("Please enter a integer amount")
            continue

    loop = asyncio.get_event_loop()
    try:
        loop.run_until_complete(main(amount))
    except KeyboardInterrupt:
        print("User exited")
        exit(1)